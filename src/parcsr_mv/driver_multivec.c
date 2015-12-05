/*BHEADER**********************************************************************
 * Copyright (c) 2006   The Regents of the University of California.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the HYPRE team. UCRL-CODE-222953.
 * All rights reserved.
 *
 * This file is part of HYPRE (see http://www.llnl.gov/CASC/hypre/).
 * Please see the COPYRIGHT_and_LICENSE file for the copyright notice, 
 * disclaimer, contact information and the GNU Lesser General Public License.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the 
 * terms of the GNU General Public License (as published by the Free Software
 * Foundation) version 2.1 dated February 1999.
 *
 * HYPRE is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the IMPLIED WARRANTY OF MERCHANTABILITY or FITNESS 
 * FOR A PARTICULAR PURPOSE.  See the terms and conditions of the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * $Revision: 2.3 $
 ***********************************************************************EHEADER*/



#include "headers.h"
 
/*--------------------------------------------------------------------------
 * Test driver for PAR multivectors (under construction)
 *--------------------------------------------------------------------------*/
 
int
main( int   argc,
      char *argv[] )
{
   hypre_ParVector   *vector1;
   hypre_ParVector   *vector2;
   hypre_ParVector   *tmp_vector;

   int          num_procs, my_id;
   int	 	global_size = 20;
   int		local_size;
   int		first_index;
   int          num_vectors, vecstride, idxstride;
   int 		i, j;
   int 		*partitioning;
   double	prod;
   double 	*data, *data2;
   hypre_Vector *vector; 
   hypre_Vector *local_vector; 
   hypre_Vector *local_vector2;
 
   /* Initialize MPI */
   MPI_Init(&argc, &argv);

   MPI_Comm_size(MPI_COMM_WORLD, &num_procs );
   MPI_Comm_rank(MPI_COMM_WORLD, &my_id );

   printf(" my_id: %d num_procs: %d\n", my_id, num_procs);
 
   partitioning = NULL;
   num_vectors = 3;
   vector1 = hypre_ParMultiVectorCreate
      ( MPI_COMM_WORLD, global_size, partitioning, num_vectors );
   partitioning = hypre_ParVectorPartitioning(vector1);

   hypre_ParVectorInitialize(vector1);
   local_vector = hypre_ParVectorLocalVector(vector1);
   data = hypre_VectorData(local_vector);
   local_size = hypre_VectorSize(local_vector);
   vecstride = hypre_VectorVectorStride(local_vector);
   idxstride = hypre_VectorIndexStride(local_vector);
   first_index = partitioning[my_id];

   printf("vecstride=%i idxstride=%i local_size=%i num_vectors=%i",
          vecstride, idxstride, local_size, num_vectors );
   for (j=0; j<num_vectors; ++j )
      for (i=0; i < local_size; i++)
         data[ j*vecstride + i*idxstride ] = first_index+i + 100*j;

   hypre_ParVectorPrint(vector1, "Vector");

   local_vector2 = hypre_SeqMultiVectorCreate( global_size, num_vectors );
   hypre_SeqVectorInitialize(local_vector2);
   data2 = hypre_VectorData(local_vector2);
   vecstride = hypre_VectorVectorStride(local_vector2);
   idxstride = hypre_VectorIndexStride(local_vector2);
   for (j=0; j<num_vectors; ++j )
      for (i=0; i < global_size; i++)
         data2[ j*vecstride + i*idxstride ] = i + 100*j;

/*   partitioning = hypre_CTAlloc(int,4);
   partitioning[0] = 0;
   partitioning[1] = 10;
   partitioning[2] = 10;
   partitioning[3] = 20;
*/
   partitioning = hypre_CTAlloc(int,1+num_procs);
   hypre_GeneratePartitioning( global_size, num_procs, &partitioning );

   vector2 = hypre_VectorToParVector(MPI_COMM_WORLD,local_vector2,partitioning);
   hypre_ParVectorSetPartitioningOwner(vector2,0);

   hypre_ParVectorPrint(vector2, "Convert");

   vector = hypre_ParVectorToVectorAll(vector2);

   /*-----------------------------------------------------------
    * Copy the vector into tmp_vector
    *-----------------------------------------------------------*/

/* Read doesn't work for multivectors yet...
   tmp_vector = hypre_ParVectorRead(MPI_COMM_WORLD, "Convert");*/
   tmp_vector = hypre_ParMultiVectorCreate
      ( MPI_COMM_WORLD, global_size, partitioning, num_vectors );
   hypre_ParVectorInitialize( tmp_vector );
   hypre_ParVectorCopy( vector2, tmp_vector );
/*
   tmp_vector = hypre_ParVectorCreate(MPI_COMM_WORLD,global_size,partitioning);
   hypre_ParVectorSetPartitioningOwner(tmp_vector,0);
   hypre_ParVectorInitialize(tmp_vector);
   hypre_ParVectorCopy(vector1, tmp_vector);

   hypre_ParVectorPrint(tmp_vector,"Copy");
*/
   /*-----------------------------------------------------------
    * Scale tmp_vector
    *-----------------------------------------------------------*/

   hypre_ParVectorScale(2.0, tmp_vector);
   hypre_ParVectorPrint(tmp_vector,"Scale");

   /*-----------------------------------------------------------
    * Do an Axpy (2*vector - vector) = vector
    *-----------------------------------------------------------*/

   hypre_ParVectorAxpy(-1.0, vector1, tmp_vector);
   hypre_ParVectorPrint(tmp_vector,"Axpy");

   /*-----------------------------------------------------------
    * Do an inner product vector* tmp_vector
    *-----------------------------------------------------------*/

   prod = hypre_ParVectorInnerProd(vector1, tmp_vector);

   printf (" prod: %8.2f \n", prod);

   /*-----------------------------------------------------------
    * Finalize things
    *-----------------------------------------------------------*/

   hypre_ParVectorDestroy(vector1);
   hypre_ParVectorDestroy(vector2); 
   hypre_ParVectorDestroy(tmp_vector);
   hypre_SeqVectorDestroy(local_vector2); 
   if (vector) hypre_SeqVectorDestroy(vector); 

   /* Finalize MPI */
   MPI_Finalize();

   return 0;
}

