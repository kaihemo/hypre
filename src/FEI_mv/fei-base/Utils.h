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



#ifndef _Utils_h_
#define _Utils_h_

#include "base/feiArray.h"

template<class T>
{
  if (len == 0) {
    insertPoint = 0;
    return(-1);
  }

  if (len == 1) {
    if (list[0] == item) return(0);
    else {
      if (list[0] < item) insertPoint = 1;
      else insertPoint = 0;
      return(-1);
    }
  }

  unsigned start = 0, end = len - 1;

  while(end - start > 1) {
    unsigned mid = (start + end) >> 1;
    if (list[mid] < item) start = mid;
    else end = mid;
  }

  if (list[start] == item) return((int)start);
  if (list[end] == item) return((int)end);

  if (list[end] < item) insertPoint = (int)end+1;
  else if (list[start] < item) insertPoint = (int)end;
  else insertPoint = (int)start;

  return(-1);
}

template<class T>
{
  if (len == 0) {
    insertPoint = 0;
    return(-1);
  }

  if (len == 1) {
    if (*(list[0]) == item) return(0);
    else {
      if (*(list[0]) < item) insertPoint = 1;
      else insertPoint = 0;
      return(-1);
    }
  }

  unsigned start = 0, end = len - 1;

  while(end - start > 1) {
    unsigned mid = (start + end) >> 1;
    if (*(list[mid]) < item) start = mid;
    else end = mid;
  }

  if (*(list[start]) == item) return((int)start);
  if (*(list[end]) == item) return((int)end);

  if ((*list[end]) < item) insertPoint = (int)end+1;
  else if (*(list[start]) < item) insertPoint = (int)end;
  else insertPoint = (int)start;

  return(-1);
}

template<class T>
{
  if (len == 0) return(-1);

  if (len == 1) {
    if (list[0] == item) return(0);
    else return(-1);
  }

  unsigned start = 0, end = len - 1;

  while(end - start > 1) {
    unsigned mid = (start + end) >> 1;
    if (list[mid] < item) start = mid;
    else end = mid;
  }

  if (list[start] == item) return((int)start);
  if (list[end] == item) return((int)end);

  return(-1);
}

template<class T>
 public:

  int operator() (T item, const T* list, int len)
    {
    }

  int operator() (T item, const T* list, int len, int& insertPoint)
    {
    }
};

{
  int insertPoint = -1;

  if (position >= 0) return(-1);
  else {
    int err = list.insert(item, insertPoint);
    if (err) return(err);
    else return(insertPoint);
  }
}

template<class T>
int Utils_merge_sorted_arrays(feiArray<T>& input, feiArray<T>& dest,
			      T* workSpace=NULL)
{
  //This function merges the array 'input' into the array 'dest', maintaining
  //sortedness in the dest array.
  //Important assumption: both arrays are assumed to be sorted on entry.
  //
  int input_len = input.length();
  if (input_len == 0) return(0);

  int old_dest_len = dest.length();
  if (old_dest_len == 0) {
    dest = input;
    return(0);
  }

  T* input_ptr = input.dataPtr();
  T* work_ptr = workSpace==NULL ? input_ptr : workSpace;

  int dest_offset = -1;

  //first let's count how many items in input don't already reside in dest.
  int numNotThere = 0;

  int insertPoint = -1;
  T* old_dest_ptr = dest.dataPtr();

  int i, offset = 0, end = old_dest_len;
  int search_offset = 0;

  for(i=0; i<input_len; i++) {
    T next_value = input_ptr[i];

				      end-search_offset, insertPoint);

    if (dest_offset < 0) {
      work_ptr[numNotThere++] = next_value;
      search_offset += insertPoint;
      offset = search_offset;
    }
    else {
      search_offset += dest_offset;
    }

    if (search_offset >= end) {
      for(int j=i+1; j<input_len; j++) work_ptr[numNotThere++] = input_ptr[j];
      break;
    }
  }

  if (numNotThere == 0) return(0);

  //now we can resize the dest array
  int new_dest_len = old_dest_len+numNotThere;
  int err = dest.resize(new_dest_len);
  if (err != 0) return(err);

  //now march down the dest and input arrays from the top, putting values in
  T* dest_ptr = dest.dataPtr();
  int new_offset = new_dest_len-1;

  for(i=numNotThere-1; i>=0; i--) {
    for(int j=end-1; j>=offset; j--) {
      dest_ptr[new_offset--] = dest_ptr[j];
    }

    dest_ptr[new_offset--] = work_ptr[i];

    end = offset;

    if (i > 0) {
    }
  }

  return(0);
}

class Utils {
 public:
   static void appendToCharArrayList(char**& strings, int& numStrings,
                                     char** stringsToAdd, int numStringsToAdd);

   static int getParam(const char* flag, int numParams, char** strings, char* param);

   static int sortedIntListFind(int item,const int* list, int len, int* insert);

   static int intListFind(int item, const int* list, int len);

   static int sortedGlobalIDListFind(GlobalID item, const GlobalID* list,
                                     int len, int* insert);

   static int sortedIntListInsert(int item, int*& list, int& len,
                                  int& allocatedLength);

   static int sortedGlobalIDListInsert(GlobalID item, GlobalID*& list,int& len,
                                       int& allocatedLength);

   static void intListInsert(int item, int index, int*& list, int& len,
                             int& allocatedLength);

   static void doubleListInsert(double item, int index, double*& list,int& len,
                             int& allocatedLength);

   static void GlobalIDListInsert(GlobalID item, int index, GlobalID*& list,
                                  int& len, int& allocatedLength);

   static void intTableInsertRow(int* newRow, int whichRow,
                                 int**& table, int& numRows);

   static void doubleTableInsertRow(double* newRow, int whichRow,
                                    double**& table, int& numRows);

   static void appendIntList(int newItem, int*& list, int& lenList);

   static void appendDoubleList(double newItem, double*& list, int& lenList);

   static bool inList(int* list, int lenList, int item);
};

#endif

