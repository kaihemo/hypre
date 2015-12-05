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
 * $Revision: 1.3 $
 ***********************************************************************EHEADER*/



/* ******************************************************************** */
/* See the file COPYRIGHT for a complete copyright notice, contact      */
/* person and disclaimer.                                               */        
/* ******************************************************************** */

#ifndef __MLOPERATOR_BLOCKMAT__
#define __MLOPERATOR_BLOCKMAT__

#include "ml_common.h"
#include "ml_operator.h"
/*****************************************************************************/
/* structure to wrap ML subblock matrices into a large ML matrix.            */
/*****************************************************************************/

struct ML_Operator_blockmat_data {
  /* Ke functions for matvec & getrow */

  int (*Ke_matvec)(ML_Operator *, int, double *, int, double *);
  int (*Ke_getrow)(ML_Operator *,int,int*,int,int*,double*,int*);
  void *Ke_matvec_data, *Ke_getrow_data, *Ke_comm_data;
  double *Ke_diag;

  /* M functions for matvec, getrow. NOTE: it is assumed    */
  /* that M's communication is identical to Ke's.           */

  int (*M_matvec)(ML_Operator *, int, double *, int, double *);
  int (*M_getrow)(ML_Operator *,int,int*,int,int*,double*,int*);
  void *M_matvec_data, *M_getrow_data;
  double *M_diag;
  ML_Operator *M_mat;
  ML_Operator *Ke_mat;
  int    destroy_M_mat;

  int N_Ke, Nghost;
  int *cols;         /* work vectors for block matrix getrow */
  double *vals;
};

#ifndef ML_CPP
#ifdef __cplusplus
extern "C" {
#endif
#endif

extern int ML_Operator_blockmat_matvec(ML_Operator *, int , double *, int, double *);
extern int ML_Operator_blockmat_comm( double *x, void *data);
extern int ML_Operator_blockmat_getrow(ML_Operator *, int, int *, int, int *, 
				       double *, int *);
extern int  ML_Operator_Gen_blockmat(ML_Operator *blockmat, 
				     ML_Operator *original1,
				     ML_Operator *original2);
extern void  ML_Operator_blockmatdata_Destroy(void *data);
extern int ML_Operator_blockmat_set_M_mat_destroy(ML_Operator *blockmat,
						  int yes_or_no);

#ifndef ML_CPP
#ifdef __cplusplus
}
#endif
#endif


#endif
