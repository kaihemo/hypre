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
 * $Revision: 2.4 $
 ***********************************************************************EHEADER*/




/******************************************************************************
 *
 * HYPRE_ParCSRBiCGSTAB interface
 *
 *****************************************************************************/
#include "headers.h"

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABCreate
 *--------------------------------------------------------------------------*/

int
HYPRE_ParCSRBiCGSTABCreate( MPI_Comm comm, HYPRE_Solver *solver )
{
   hypre_BiCGSTABFunctions * bicgstab_functions =
      hypre_BiCGSTABFunctionsCreate(
         hypre_ParKrylovCreateVector,
         hypre_ParKrylovDestroyVector, hypre_ParKrylovMatvecCreate,
         hypre_ParKrylovMatvec, hypre_ParKrylovMatvecDestroy,
         hypre_ParKrylovInnerProd, hypre_ParKrylovCopyVector,
         hypre_ParKrylovScaleVector, hypre_ParKrylovAxpy,
         hypre_ParKrylovCommInfo,
         hypre_ParKrylovIdentitySetup, hypre_ParKrylovIdentity );

   *solver = ( (HYPRE_Solver) hypre_BiCGSTABCreate( bicgstab_functions) );
   if (!solver)
      hypre_error_in_arg(2);
    
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABDestroy
 *--------------------------------------------------------------------------*/

int 
HYPRE_ParCSRBiCGSTABDestroy( HYPRE_Solver solver )
{
   return( hypre_BiCGSTABDestroy( (void *) solver ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetup
 *--------------------------------------------------------------------------*/

int 
HYPRE_ParCSRBiCGSTABSetup( HYPRE_Solver solver,
                        HYPRE_ParCSRMatrix A,
                        HYPRE_ParVector b,
                        HYPRE_ParVector x      )
{
   return( HYPRE_BiCGSTABSetup( solver,
                                (HYPRE_Matrix) A,
                                (HYPRE_Vector) b,
                                (HYPRE_Vector) x ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSolve
 *--------------------------------------------------------------------------*/

int 
HYPRE_ParCSRBiCGSTABSolve( HYPRE_Solver solver,
                        HYPRE_ParCSRMatrix A,
                        HYPRE_ParVector b,
                        HYPRE_ParVector x      )
{
   return( HYPRE_BiCGSTABSolve( solver,
                                (HYPRE_Matrix) A,
                                (HYPRE_Vector) b,
                                (HYPRE_Vector) x ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetTol
 *--------------------------------------------------------------------------*/

int
HYPRE_ParCSRBiCGSTABSetTol( HYPRE_Solver solver,
                         double             tol    )
{
   return( HYPRE_BiCGSTABSetTol( solver, tol ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetMinIter
 *--------------------------------------------------------------------------*/

int
HYPRE_ParCSRBiCGSTABSetMinIter( HYPRE_Solver solver,
                             int          min_iter )
{
   return( HYPRE_BiCGSTABSetMinIter( solver, min_iter ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetMaxIter
 *--------------------------------------------------------------------------*/

int
HYPRE_ParCSRBiCGSTABSetMaxIter( HYPRE_Solver solver,
                             int          max_iter )
{
   return( HYPRE_BiCGSTABSetMaxIter( solver, max_iter ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetStopCrit
 *--------------------------------------------------------------------------*/

int
HYPRE_ParCSRBiCGSTABSetStopCrit( HYPRE_Solver solver,
                              int          stop_crit )
{
   return( HYPRE_BiCGSTABSetStopCrit( solver, stop_crit ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetPrecond
 *--------------------------------------------------------------------------*/

int
HYPRE_ParCSRBiCGSTABSetPrecond( HYPRE_Solver         solver,
                                HYPRE_PtrToParSolverFcn precond,
                                HYPRE_PtrToParSolverFcn precond_setup,
                                HYPRE_Solver         precond_solver )
{
   return( HYPRE_BiCGSTABSetPrecond( solver,
                                     (HYPRE_PtrToSolverFcn) precond,
                                     (HYPRE_PtrToSolverFcn) precond_setup,
                                     precond_solver ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABGetPrecond
 *--------------------------------------------------------------------------*/

int
HYPRE_ParCSRBiCGSTABGetPrecond( HYPRE_Solver  solver,
                             HYPRE_Solver *precond_data_ptr )
{
   return( HYPRE_BiCGSTABGetPrecond( solver, precond_data_ptr ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetLogging
 *--------------------------------------------------------------------------*/

int
HYPRE_ParCSRBiCGSTABSetLogging( HYPRE_Solver solver,
                             int logging)
{
   return( HYPRE_BiCGSTABSetLogging( solver, logging ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetPrintLevel
 *--------------------------------------------------------------------------*/

int
HYPRE_ParCSRBiCGSTABSetPrintLevel( HYPRE_Solver solver,
                             int print_level)
{
   return( HYPRE_BiCGSTABSetPrintLevel( solver, print_level ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABGetNumIterations
 *--------------------------------------------------------------------------*/

int
HYPRE_ParCSRBiCGSTABGetNumIterations( HYPRE_Solver  solver,
                                   int                *num_iterations )
{
   return( HYPRE_BiCGSTABGetNumIterations( solver, num_iterations ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABGetFinalRelativeResidualNorm
 *--------------------------------------------------------------------------*/

int
HYPRE_ParCSRBiCGSTABGetFinalRelativeResidualNorm( HYPRE_Solver  solver,
                                               double             *norm   )
{
   return( HYPRE_BiCGSTABGetFinalRelativeResidualNorm( solver, norm ) );
}
