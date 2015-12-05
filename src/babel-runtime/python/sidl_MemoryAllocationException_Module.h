/*
 * File:          sidl_MemoryAllocationException_Module.h
 * Symbol:        sidl.MemoryAllocationException-v0.9.15
 * Symbol Type:   class
 * Babel Version: 1.0.0
 * Release:       $Name: V1-13-0b $
 * Revision:      @(#) $Id: sidl_MemoryAllocationException_Module.h,v 1.1 2006/08/29 23:39:46 painter Exp $
 * Description:   expose a constructor for the Python wrapper
 * 
 * Copyright (c) 2000-2002, The Regents of the University of California.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the Components Team <components@llnl.gov>
 * All rights reserved.
 * 
 * This file is part of Babel. For more information, see
 * http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
 * for Our Notice and the LICENSE file for the GNU Lesser General Public
 * License.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License (as published by
 * the Free Software Foundation) version 2.1 dated February 1999.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
 * conditions of the GNU Lesser General Public License for more details.
 * 
 * You should have recieved a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * THIS CODE IS AUTOMATICALLY GENERATED BY THE BABEL
 * COMPILER. DO NOT EDIT THIS!
 * 
 * External clients need an entry point to wrap a pointer
 * to an instance of sidl.MemoryAllocationException.
 * This header files defines two methods that such clients
 * will need.
 *     sidl_MemoryAllocationException__import
 *         This should be called in the client's init
 *         module method.
 *     sidl_MemoryAllocationException__wrap
 *         This will wrap an IOR in a Python object.
 * This object can be used as an exception. It exports
 * a Python exception type that may be needed as well.
 *     sidl_MemoryAllocationException__type
 *         A Python exception type corresponding to
 *         this object type.
 * Here is the pattern for throwing an exception:
 *   PyObject *obj = sidl_MemoryAllocationException__wrap(ex);
 *   PyErr_SetObject(sidl_MemoryAllocationException__type, obj);
 *   Py_XDECREF(obj);
 */

#ifndef included_sidl_MemoryAllocationException_MODULE
#define included_sidl_MemoryAllocationException_MODULE

#include <Python.h>
#include "sidlType.h"
#ifdef HAVE_PTHREAD
#include <pthread.h>
#endif /* HAVE_PTHREAD */

#ifdef __cplusplus
extern "C" {
#endif

struct sidl__array;

/* Forward declaration of IOR structure */
struct sidl_MemoryAllocationException__object;
struct sidl_MemoryAllocationException__array;
struct sidl_BaseInterface__object;

#define sidl_MemoryAllocationException__wrap_NUM 0
#define sidl_MemoryAllocationException__wrap_RETURN PyObject *
#define sidl_MemoryAllocationException__wrap_PROTO (struct sidl_MemoryAllocationException__object *sidlobj)

#define sidl_MemoryAllocationException__convert_NUM 1
#define sidl_MemoryAllocationException__convert_RETURN int
#define sidl_MemoryAllocationException__convert_PROTO (PyObject *obj, struct sidl_MemoryAllocationException__object **sidlobj)

#define sidl_MemoryAllocationException__convert_python_array_NUM 2
#define sidl_MemoryAllocationException__convert_python_array_RETURN int
#define sidl_MemoryAllocationException__convert_python_array_PROTO (PyObject *obj, struct sidl_MemoryAllocationException__array **sidlarray)

#define sidl_MemoryAllocationException__convert_sidl_array_NUM 3
#define sidl_MemoryAllocationException__convert_sidl_array_RETURN PyObject *
#define sidl_MemoryAllocationException__convert_sidl_array_PROTO (struct sidl__array *sidlarray)

#define sidl_MemoryAllocationException__weakRef_NUM 4
#define sidl_MemoryAllocationException__weakRef_RETURN PyObject *
#define sidl_MemoryAllocationException__weakRef_PROTO (struct sidl_MemoryAllocationException__object *sidlobj)

#define sidl_MemoryAllocationException_deref_NUM 5
#define sidl_MemoryAllocationException_deref_RETURN void
#define sidl_MemoryAllocationException_deref_PROTO (struct sidl_MemoryAllocationException__object *sidlobj)

#define sidl_MemoryAllocationException__newRef_NUM 6
#define sidl_MemoryAllocationException__newRef_RETURN PyObject *
#define sidl_MemoryAllocationException__newRef_PROTO (struct sidl_MemoryAllocationException__object *sidlobj)

#define sidl_MemoryAllocationException__addRef_NUM 7
#define sidl_MemoryAllocationException__addRef_RETURN void
#define sidl_MemoryAllocationException__addRef_PROTO (struct sidl_MemoryAllocationException__object *sidlobj)

#define sidl_MemoryAllocationException_PyType_NUM 8
#define sidl_MemoryAllocationException_PyType_RETURN PyTypeObject *
#define sidl_MemoryAllocationException_PyType_PROTO (void)

#define sidl_MemoryAllocationException__connectI_NUM 9
#define sidl_MemoryAllocationException__connectI_RETURN struct sidl_MemoryAllocationException__object* 
#define sidl_MemoryAllocationException__connectI_PROTO (const char* url, sidl_bool ar, struct sidl_BaseInterface__object ** _ex)

#define sidl_MemoryAllocationException__rmicast_NUM 10
#define sidl_MemoryAllocationException__rmicast_RETURN struct sidl_MemoryAllocationException__object* 
#define sidl_MemoryAllocationException__rmicast_PROTO (void* bi, struct sidl_BaseInterface__object ** _ex)

#define sidl_MemoryAllocationException__type_NUM 11

#define sidl_MemoryAllocationException__API_NUM 12

#ifdef sidl_MemoryAllocationException_INTERNAL

#define sidl_MemoryAllocationException__import() ;


/*
 * This declaration is not for clients.
 */

static sidl_MemoryAllocationException__wrap_RETURN
sidl_MemoryAllocationException__wrap
sidl_MemoryAllocationException__wrap_PROTO;

static sidl_MemoryAllocationException__convert_RETURN
sidl_MemoryAllocationException__convert
sidl_MemoryAllocationException__convert_PROTO;

static sidl_MemoryAllocationException__convert_python_array_RETURN
sidl_MemoryAllocationException__convert_python_array
sidl_MemoryAllocationException__convert_python_array_PROTO;

static sidl_MemoryAllocationException__convert_sidl_array_RETURN
sidl_MemoryAllocationException__convert_sidl_array
sidl_MemoryAllocationException__convert_sidl_array_PROTO;

static sidl_MemoryAllocationException__weakRef_RETURN
sidl_MemoryAllocationException__weakRef
sidl_MemoryAllocationException__weakRef_PROTO;

static sidl_MemoryAllocationException_deref_RETURN
sidl_MemoryAllocationException_deref
sidl_MemoryAllocationException_deref_PROTO;

static sidl_MemoryAllocationException__newRef_RETURN
sidl_MemoryAllocationException__newRef
sidl_MemoryAllocationException__newRef_PROTO;

static sidl_MemoryAllocationException__addRef_RETURN
sidl_MemoryAllocationException__addRef
sidl_MemoryAllocationException__addRef_PROTO;

static sidl_MemoryAllocationException_PyType_RETURN
sidl_MemoryAllocationException_PyType
sidl_MemoryAllocationException_PyType_PROTO;

static PyObject *
sidl_MemoryAllocationException__type;

#else

static void **sidl_MemoryAllocationException__API = NULL;

#define sidl_MemoryAllocationException__wrap \
  (*((sidl_MemoryAllocationException__wrap_RETURN (*) \
  sidl_MemoryAllocationException__wrap_PROTO) \
  (sidl_MemoryAllocationException__API \
  [sidl_MemoryAllocationException__wrap_NUM])))

#define sidl_MemoryAllocationException__convert \
  (*((sidl_MemoryAllocationException__convert_RETURN (*) \
  sidl_MemoryAllocationException__convert_PROTO) \
  (sidl_MemoryAllocationException__API \
  [sidl_MemoryAllocationException__convert_NUM])))

#define sidl_MemoryAllocationException__convert_python_array \
  (*((sidl_MemoryAllocationException__convert_python_array_RETURN (*) \
  sidl_MemoryAllocationException__convert_python_array_PROTO) \
  (sidl_MemoryAllocationException__API \
  [sidl_MemoryAllocationException__convert_python_array_NUM])))

#define sidl_MemoryAllocationException__convert_sidl_array \
  (*((sidl_MemoryAllocationException__convert_sidl_array_RETURN (*) \
  sidl_MemoryAllocationException__convert_sidl_array_PROTO) \
  (sidl_MemoryAllocationException__API \
  [sidl_MemoryAllocationException__convert_sidl_array_NUM])))

#define sidl_MemoryAllocationException__weakRef \
  (*((sidl_MemoryAllocationException__weakRef_RETURN (*) \
  sidl_MemoryAllocationException__weakRef_PROTO) \
  (sidl_MemoryAllocationException__API \
  [sidl_MemoryAllocationException__weakRef_NUM])))

#define sidl_MemoryAllocationException_deref \
  (*((sidl_MemoryAllocationException_deref_RETURN (*) \
  sidl_MemoryAllocationException_deref_PROTO) \
  (sidl_MemoryAllocationException__API \
  [sidl_MemoryAllocationException_deref_NUM])))

#define sidl_MemoryAllocationException__newRef \
  (*((sidl_MemoryAllocationException__newRef_RETURN (*) \
  sidl_MemoryAllocationException__newRef_PROTO) \
  (sidl_MemoryAllocationException__API \
  [sidl_MemoryAllocationException__newRef_NUM])))

#define sidl_MemoryAllocationException__addRef \
  (*((sidl_MemoryAllocationException__addRef_RETURN (*) \
  sidl_MemoryAllocationException__addRef_PROTO) \
  (sidl_MemoryAllocationException__API \
  [sidl_MemoryAllocationException__addRef_NUM])))

#define sidl_MemoryAllocationException_PyType \
  (*((sidl_MemoryAllocationException_PyType_RETURN (*) \
  sidl_MemoryAllocationException_PyType_PROTO) \
  (sidl_MemoryAllocationException__API \
  [sidl_MemoryAllocationException_PyType_NUM])))

#define sidl_MemoryAllocationException__connectI \
  (*((sidl_MemoryAllocationException__connectI_RETURN (*) \
  sidl_MemoryAllocationException__connectI_PROTO) \
  (sidl_MemoryAllocationException__API \
  [sidl_MemoryAllocationException__connectI_NUM])))

#define sidl_MemoryAllocationException__rmicast \
  (*((sidl_MemoryAllocationException__rmicast_RETURN (*) \
  sidl_MemoryAllocationException__rmicast_PROTO) \
  (sidl_MemoryAllocationException__API \
  [sidl_MemoryAllocationException__rmicast_NUM])))

#define sidl_MemoryAllocationException__type \
  ((PyObject *)(sidl_MemoryAllocationException__API[sidl_MemoryAllocationException__type_NUM]))

#ifdef HAVE_PTHREAD
#define sidl_MemoryAllocationException__import() \
{ \
  pthread_mutex_t __sidl_pyapi_mutex = PTHREAD_MUTEX_INITIALIZER; \
  pthread_mutex_lock(&__sidl_pyapi_mutex); \
  if (!sidl_MemoryAllocationException__API) { \
    PyObject *module = PyImport_ImportModule("sidl.MemoryAllocationException"); \
    if (module != NULL) { \
      PyObject *module_dict = PyModule_GetDict(module); \
      PyObject *c_api_object = \
        PyDict_GetItemString(module_dict, "_C_API"); \
      if (c_api_object && PyCObject_Check(c_api_object)) { \
        sidl_MemoryAllocationException__API = \
          (void **)PyCObject_AsVoidPtr(c_api_object); \
      } \
      else { fprintf(stderr, "babel: sidl_MemoryAllocationException__import failed to lookup _C_API (%p %p %s).\n", c_api_object, c_api_object ? c_api_object->ob_type : NULL, c_api_object ? c_api_object->ob_type->tp_name : ""); }\
      Py_DECREF(module); \
    } else { fprintf(stderr, "babel: sidl_MemoryAllocationException__import failed to import its module.\n"); }\
  }\
  pthread_mutex_unlock(&__sidl_pyapi_mutex); \
  pthread_mutex_destroy(&__sidl_pyapi_mutex); \
}
#else /* !HAVE_PTHREAD */
#define sidl_MemoryAllocationException__import() \
if (!sidl_MemoryAllocationException__API) { \
  PyObject *module = PyImport_ImportModule("sidl.MemoryAllocationException"); \
  if (module != NULL) { \
    PyObject *module_dict = PyModule_GetDict(module); \
    PyObject *c_api_object = \
      PyDict_GetItemString(module_dict, "_C_API"); \
    if (c_api_object && PyCObject_Check(c_api_object)) { \
      sidl_MemoryAllocationException__API = \
        (void **)PyCObject_AsVoidPtr(c_api_object); \
    } \
    else { fprintf(stderr, "babel: sidl_MemoryAllocationException__import failed to lookup _C_API (%p %p %s).\n", c_api_object, c_api_object ? c_api_object->ob_type : NULL, c_api_object ? c_api_object->ob_type->tp_name : ""); }\
    Py_DECREF(module); \
  } else { fprintf(stderr, "babel: sidl_MemoryAllocationException__import failed to import its module.\n"); }\
}
#endif /* HAVE_PTHREAD */

#endif

#ifdef __cplusplus
}
#endif

#endif
