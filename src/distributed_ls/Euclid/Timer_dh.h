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
 * $Revision: 2.5 $
 ***********************************************************************EHEADER*/



#ifndef TIMER_DH_H
#define TIMER_DH_H

#include "euclid_common.h"

/*--------------------------------------------------------------*/
/* Stuph in this block isn't really needed for multi-processor
 * runs, since recording CPU time probably isn't useful.
 * if EUCLID_TIMING is defined in $PCPACK_DIR/bmake_XXX/common,
 * the times() function is used;
 * then MPI_Wtime() is used in preference to times().
 *
 * You may need to fiddle with some of these includes, depending
 * on your system.  Make sure and check the logFile to ensure
 * that CLK_TCK was properly defined.  See Timer_dhCreate()
 * for additional details. 
 *
 * if "JUNK_TIMING" is defined during compilation, timing functions
 * either do nothing, or return -1.0; this is primarily for debugging.
 */

#include "HYPRE_config.h"

#ifdef EUCLID_TIMING
#include <sys/times.h>
#include <sys/types.h>
#if HAVE_UNISTD_H
#  include <unistd.h>
#endif /* HAVE_UNISTD_H */

#elif !defined(JUNK_TIMING)
/* #include <sys/types.h> 
#include <sys/sysconfig.h>
*/
#ifdef WIN32
#  include <time.h>
#endif
#if HAVE_UNISTD_H
#  include <unistd.h>  /* needed for sysconf(_SC_CLK_TCK) */
#endif /* HAVE_UNISTD_H */
#endif


/* 
   ??? may be needed for some compilers/platforms?
#include <limits.h>
#include <time.h>
#include <sys/resource.h>
*/

/*--------------------------------------------------------------*/


struct _timer_dh {
  bool isRunning;
  long int sc_clk_tck;
  double begin_wall; 
  double end_wall;

#ifdef EUCLID_TIMING
  struct tms  begin_cpu;
  struct tms  end_cpu;
#endif
 
};

extern void Timer_dhCreate(Timer_dh *t);
extern void Timer_dhDestroy(Timer_dh t);
extern void Timer_dhStart(Timer_dh t);
extern void Timer_dhStop(Timer_dh t);
extern double Timer_dhReadCPU(Timer_dh t);
extern double Timer_dhReadWall(Timer_dh t);
extern double Timer_dhReadUsage(Timer_dh t);

/* notes:
    (1)  unless compiled with EUCLID_TIMING defined, readCPU 
         and readUseage return -1.0.
    (2)  whenever start() is called, the timer is reset; you
         don't need to call stop() first.
    (3)  if stop() HAS been called, the readXX functions return
         timings between start() and stop(); , if start()
         was called but not stop(), they sample the time then
         return; if start() was never called, they return junk.
*/


#endif
