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
 * $Revision: 2.7 $
 ***********************************************************************EHEADER*/




#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "utilities/utilities.h"
#include "HYPRE.h"
#include "IJ_mv/HYPRE_IJ_mv.h"
#include "parcsr_mv/HYPRE_parcsr_mv.h"
#include "parcsr_mv/parcsr_mv.h"
#include "parcsr_ls/HYPRE_parcsr_ls.h"

/******************************************************************************
 *
 * HYPRE_ParCSRTFQmr interface
 *
 *****************************************************************************/

extern void *hypre_TFQmrCreate();
extern int hypre_TFQmrDestroy(void *);
extern int hypre_TFQmrSetup(void *, void *, void *, void *);
extern int hypre_TFQmrSolve(void *, void *, void *, void *);
extern int hypre_TFQmrSetTol(void *, double);
extern int hypre_TFQmrSetMaxIter(void *, int);
extern int hypre_TFQmrSetStopCrit(void *, int);
extern int hypre_TFQmrSetPrecond(void *, int (*precond)(),
                                 int (*precond_setup)(), void *);
extern int hypre_TFQmrSetLogging(void *, int);
extern int hypre_TFQmrGetNumIterations(void *, int *);
extern int hypre_TFQmrGetFinalRelativeResidualNorm(void *, double *);

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRTFQmrCreate
 *--------------------------------------------------------------------------*/

int HYPRE_ParCSRTFQmrCreate( MPI_Comm comm, HYPRE_Solver *solver )
{
   *solver = (HYPRE_Solver) hypre_TFQmrCreate( );

   return 0;
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRTFQmrDestroy
 *--------------------------------------------------------------------------*/

int HYPRE_ParCSRTFQmrDestroy( HYPRE_Solver solver )
{
   return( hypre_TFQmrDestroy( (void *) solver ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRTFQmrSetup
 *--------------------------------------------------------------------------*/

int HYPRE_ParCSRTFQmrSetup( HYPRE_Solver solver, HYPRE_ParCSRMatrix A,
                               HYPRE_ParVector b, HYPRE_ParVector x      )
{
   return( hypre_TFQmrSetup( (void *) solver, (void *) A, (void *) b,
                                 (void *) x ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRTFQmrSolve
 *--------------------------------------------------------------------------*/

int HYPRE_ParCSRTFQmrSolve( HYPRE_Solver solver, HYPRE_ParCSRMatrix A,
                                HYPRE_ParVector b, HYPRE_ParVector x      )
{
   return( hypre_TFQmrSolve( (void *) solver, (void *) A,
                                 (void *) b, (void *) x ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRTFQmrSetTol
 *--------------------------------------------------------------------------*/

int HYPRE_ParCSRTFQmrSetTol( HYPRE_Solver solver, double tol )
{
   return( hypre_TFQmrSetTol( (void *) solver, tol ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRTFQmrSetMaxIter
 *--------------------------------------------------------------------------*/

int HYPRE_ParCSRTFQmrSetMaxIter( HYPRE_Solver solver, int max_iter )
{
   return( hypre_TFQmrSetMaxIter( (void *) solver, max_iter ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRTFQmretStopCrit
 *--------------------------------------------------------------------------*/

int HYPRE_ParCSRTFQmrSetStopCrit( HYPRE_Solver solver, int stop_crit )
{
   return( hypre_TFQmrSetStopCrit( (void *) solver, stop_crit ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRTFQmrSetPrecond
 *--------------------------------------------------------------------------*/

int HYPRE_ParCSRTFQmrSetPrecond( HYPRE_Solver  solver,
          int (*precond)      (HYPRE_Solver sol, HYPRE_ParCSRMatrix matrix,
			       HYPRE_ParVector b, HYPRE_ParVector x),
          int (*precond_setup)(HYPRE_Solver sol, HYPRE_ParCSRMatrix matrix,
			       HYPRE_ParVector b, HYPRE_ParVector x),
          void               *precond_data )
{
   return( hypre_TFQmrSetPrecond( (void *) solver,
                                precond, precond_setup, precond_data ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRTFQmrSetLogging
 *--------------------------------------------------------------------------*/

int HYPRE_ParCSRTFQmrSetLogging( HYPRE_Solver solver, int logging)
{
   return( hypre_TFQmrSetLogging( (void *) solver, logging ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRTFQmretNumIterations
 *--------------------------------------------------------------------------*/

int HYPRE_ParCSRTFQmrGetNumIterations(HYPRE_Solver solver,int *num_iterations)
{
   return( hypre_TFQmrGetNumIterations( (void *) solver, num_iterations ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRTFQmrGetFinalRelativeResidualNorm
 *--------------------------------------------------------------------------*/

int HYPRE_ParCSRTFQmrGetFinalRelativeResidualNorm( HYPRE_Solver  solver,
                                                       double *norm   )
{
   return( hypre_TFQmrGetFinalRelativeResidualNorm( (void *) solver, norm ) );
}

