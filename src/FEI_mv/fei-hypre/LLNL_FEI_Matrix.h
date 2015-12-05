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



/***************************************************************************
  Module:  LLNL_FEI_Matrix.h
  Purpose: custom implementation of the FEI/Matrix 
 ***************************************************************************/

#ifndef _LLNL_FEI_MATRIX_H_
#define _LLNL_FEI_MATRIX_H_

#include "utilities.h"
#include "HYPRE.h"

/**************************************************************************
 definition of the class to capture the FEI matrix information 
---------------------------------------------------------------------------*/

class LLNL_FEI_Matrix
{
   MPI_Comm mpiComm_;
   int      mypid_;
   int      outputLevel_;

   int    localNRows_;
   int    nConstraints_;
   int    extNRows_;
   int    *constrEqns_;
   int    *globalEqnOffsets_;
   int    *globalCROffsets_;
   int    *extColMap_;

   int    *diagIA_;
   int    *diagJA_;
   double *diagAA_;
   int    *offdIA_;
   int    *offdJA_;
   double *offdAA_;
   double *diagonal_;

   int    nRecvs_;
   int    *recvLengs_;
   int    *recvProcs_;
   int    *recvProcIndices_;
   double *dRecvBufs_;
   double *dExtBufs_;

   int    nSends_;
   int    *sendLengs_;
   int    *sendProcs_;
   int    *sendProcIndices_;
   double *dSendBufs_;
   MPI_Request *mpiRequests_;

   int    FLAG_PrintMatrix_;
   int    FLAG_MatrixOverlap_;

public :

   LLNL_FEI_Matrix(MPI_Comm comm);
   ~LLNL_FEI_Matrix();

   int     parameters(int numParams, char **paramString);

   int     resetMatrix(double s);

   int     setMatrix(int nRows, int *diagIA, int *diagJA, double *diagAA, 
                     int nExtRows, int *colMap, int *offdIA, int *offdJA, 
                     double *offdAA, double *diagonal, int *eqnOffsets,
                     int *crOffsets);

   int     setCommPattern(int nRecvs, int *recvLengs, int *recvProcs, 
                          int *recvProcIndices, int nSends, int *sendLengs, 
                          int *sendProcs, int *sendProcIndices);

   int     setComplete();

   int     setConstraints(int nConstraints, int *constEqns);

   int     residualNorm(int whichNorm, double *solnVector, double *rhsVector, 
                        double* norms);

   int     getNumLocalRows() {return localNRows_;}
   int     getNumExtRows() {return extNRows_;}
   int     *getEqnOffsets() {return globalEqnOffsets_;}
   double *getMatrixDiagonal() {return diagonal_;}
   int     getLocalMatrix(int *nrows, int **ia, int **ja, double **aa) 
                         {(*nrows) = localNRows_; (*ia) = diagIA_;
                          (*ja) = diagJA_; (*aa) = diagAA_; return 0; }
   int     getExtMatrix(int *nrows, int **ia, int **ja, double **aa, int **map) 
                         {(*nrows) = extNRows_; (*ia) = offdIA_;
                          (*ja) = offdJA_; (*aa) = offdAA_; 
                          (*map) = extColMap_; return 0; }

   void    matvec(double *x, double *y);

private:
   void scatterDData(double *x);
   void gatherAddDData(double *x);
   void printMatrix();
   void matMult(int ANRows, int ANCols, int *AIA, int *AJA, double *AAA, 
                int BNRows, int BNCols, int *BIA, int *BJA, double *BAA, 
                int *DNRows, int *DNCols, int **DIA, int **DJA, double **DAA);
   void exchangeSubMatrices();
   int  BinarySearch2(int *list, int start, int lsize, int ind);
   void IntSort(int *list1, int start, int theEnd);
   void IntSort2(int *list1, int *list2, int start, int theEnd);
   void IntSort2a(int *list1, double *list2, int start, int theEnd);
};

#endif /* endif for _LLNL_FEI_MATRIX_H_ */

