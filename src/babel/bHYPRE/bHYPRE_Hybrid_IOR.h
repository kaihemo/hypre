/*
 * File:          bHYPRE_Hybrid_IOR.h
 * Symbol:        bHYPRE.Hybrid-v1.0.0
 * Symbol Type:   class
 * Babel Version: 1.0.0
 * Description:   Intermediate Object Representation for bHYPRE.Hybrid
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_bHYPRE_Hybrid_IOR_h
#define included_bHYPRE_Hybrid_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
struct sidl_rmi_InstanceHandle__object;
#ifndef included_bHYPRE_Operator_IOR_h
#include "bHYPRE_Operator_IOR.h"
#endif
#ifndef included_bHYPRE_Solver_IOR_h
#include "bHYPRE_Solver_IOR.h"
#endif
#ifndef included_sidl_BaseClass_IOR_h
#include "sidl_BaseClass_IOR.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Symbol "bHYPRE.Hybrid" (version 1.0.0)
 * 
 * Hybrid solver
 * first tries to solve with the specified Krylov solver, preconditioned by
 * diagonal scaling (this combination is the "first solver")
 * If that fails to converge, it will try again with the user-specified
 * preconditioner (this combination is the "second solver").
 * 
 * Specify the preconditioner  by calling SecondSolver's SetPreconditioner
 * method.  If no preconditioner is specified (equivalently, if the
 * preconditioner for SecondSolver is IdentitySolver), the preconditioner for
 * the second try will be one of the following defaults.
 * StructMatrix: SMG.  other matrix types: not implemented
 * 
 * The Hybrid solver's Setup method will call Setup on KrylovSolver, so the
 * user should not call Setup on KrylovSolver.
 */

struct bHYPRE_Hybrid__array;
struct bHYPRE_Hybrid__object;
struct bHYPRE_Hybrid__sepv;

/*
 * Forward references for external classes and interfaces.
 */

struct bHYPRE_MPICommunicator__array;
struct bHYPRE_MPICommunicator__object;
struct bHYPRE_PreconditionedSolver__array;
struct bHYPRE_PreconditionedSolver__object;
struct bHYPRE_Vector__array;
struct bHYPRE_Vector__object;
struct sidl_BaseException__array;
struct sidl_BaseException__object;
struct sidl_BaseInterface__array;
struct sidl_BaseInterface__object;
struct sidl_ClassInfo__array;
struct sidl_ClassInfo__object;
struct sidl_RuntimeException__array;
struct sidl_RuntimeException__object;
struct sidl_rmi_Call__array;
struct sidl_rmi_Call__object;
struct sidl_rmi_Return__array;
struct sidl_rmi_Return__object;

/*
 * Declare the static method entry point vector.
 */

struct bHYPRE_Hybrid__sepv {
  /* Implicit builtin methods */
  /* 0 */
  /* 1 */
  /* 2 */
  /* 3 */
  /* 4 */
  /* 5 */
  /* 6 */
  void (*f__set_hooks_static)(
    /* in */ sidl_bool on,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* 7 */
  /* 8 */
  /* 9 */
  /* 10 */
  /* 11 */
  /* 12 */
  /* 13 */
  /* Methods introduced in sidl.BaseInterface-v0.9.15 */
  /* Methods introduced in sidl.BaseClass-v0.9.15 */
  /* Methods introduced in bHYPRE.Operator-v1.0.0 */
  /* Methods introduced in bHYPRE.Solver-v1.0.0 */
  /* Methods introduced in bHYPRE.Hybrid-v1.0.0 */
  struct bHYPRE_Hybrid__object* (*f_Create)(
    /* in */ struct bHYPRE_MPICommunicator__object* mpi_comm,
    /* in */ struct bHYPRE_PreconditionedSolver__object* SecondSolver,
    /* in */ struct bHYPRE_Operator__object* A,
    /* out */ struct sidl_BaseInterface__object* *_ex);
};

/*
 * Declare the method entry point vector.
 */

struct bHYPRE_Hybrid__epv {
  /* Implicit builtin methods */
  /* 0 */
  void* (*f__cast)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* 1 */
  void (*f__delete)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* 2 */
  void (*f__exec)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* 3 */
  char* (*f__getURL)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* 4 */
  void (*f__raddRef)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* 5 */
  sidl_bool (*f__isRemote)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* 6 */
  void (*f__set_hooks)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ sidl_bool on,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* 7 */
  void (*f__ctor)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* 8 */
  void (*f__ctor2)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* 9 */
  void (*f__dtor)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* 10 */
  /* 11 */
  /* 12 */
  /* 13 */
  /* Methods introduced in sidl.BaseInterface-v0.9.15 */
  void (*f_addRef)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  void (*f_deleteRef)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  sidl_bool (*f_isType)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* Methods introduced in sidl.BaseClass-v0.9.15 */
  /* Methods introduced in bHYPRE.Operator-v1.0.0 */
  int32_t (*f_SetCommunicator)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ struct bHYPRE_MPICommunicator__object* mpi_comm,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  void (*f_Destroy)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_SetIntParameter)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ const char* name,
    /* in */ int32_t value,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_SetDoubleParameter)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ const char* name,
    /* in */ double value,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_SetStringParameter)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ const char* name,
    /* in */ const char* value,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_SetIntArray1Parameter)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ const char* name,
    /* in rarray[nvalues] */ struct sidl_int__array* value,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_SetIntArray2Parameter)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ const char* name,
    /* in array<int,2,column-major> */ struct sidl_int__array* value,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_SetDoubleArray1Parameter)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ const char* name,
    /* in rarray[nvalues] */ struct sidl_double__array* value,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_SetDoubleArray2Parameter)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ const char* name,
    /* in array<double,2,column-major> */ struct sidl_double__array* value,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_GetIntValue)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ const char* name,
    /* out */ int32_t* value,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_GetDoubleValue)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ const char* name,
    /* out */ double* value,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_Setup)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ struct bHYPRE_Vector__object* b,
    /* in */ struct bHYPRE_Vector__object* x,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_Apply)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ struct bHYPRE_Vector__object* b,
    /* inout */ struct bHYPRE_Vector__object** x,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_ApplyAdjoint)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ struct bHYPRE_Vector__object* b,
    /* inout */ struct bHYPRE_Vector__object** x,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* Methods introduced in bHYPRE.Solver-v1.0.0 */
  int32_t (*f_SetOperator)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ struct bHYPRE_Operator__object* A,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_SetTolerance)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ double tolerance,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_SetMaxIterations)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ int32_t max_iterations,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_SetLogging)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ int32_t level,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_SetPrintLevel)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* in */ int32_t level,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_GetNumIterations)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ int32_t* num_iterations,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_GetRelResidualNorm)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ double* norm,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  /* Methods introduced in bHYPRE.Hybrid-v1.0.0 */
  int32_t (*f_GetFirstSolver)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ struct bHYPRE_PreconditionedSolver__object** FirstSolver,
    /* out */ struct sidl_BaseInterface__object* *_ex);
  int32_t (*f_GetSecondSolver)(
    /* in */ struct bHYPRE_Hybrid__object* self,
    /* out */ struct bHYPRE_PreconditionedSolver__object** SecondSolver,
    /* out */ struct sidl_BaseInterface__object* *_ex);
};

/*
 * Define the controls structure.
 */


struct bHYPRE_Hybrid__controls {
  int     use_hooks;
};
/*
 * Define the class object structure.
 */

struct bHYPRE_Hybrid__object {
  struct sidl_BaseClass__object  d_sidl_baseclass;
  struct bHYPRE_Operator__object d_bhypre_operator;
  struct bHYPRE_Solver__object   d_bhypre_solver;
  struct bHYPRE_Hybrid__epv*     d_epv;
  void*                          d_data;
};

struct bHYPRE_Hybrid__external {
  struct bHYPRE_Hybrid__object*
  (*createObject)(void* ddata, struct sidl_BaseInterface__object **_ex);

  struct bHYPRE_Hybrid__sepv*
  (*getStaticEPV)(void);
  struct sidl_BaseClass__epv*(*getSuperEPV)(void);
  int d_ior_major_version;
  int d_ior_minor_version;
};

/*
 * This function returns a pointer to a static structure of
 * pointers to function entry points.  Its purpose is to provide
 * one-stop shopping for loading DLLs.
 */

const struct bHYPRE_Hybrid__external*
bHYPRE_Hybrid__externals(void);

extern struct bHYPRE_Hybrid__object*
bHYPRE_Hybrid__new(void* ddata,struct sidl_BaseInterface__object ** _ex);

extern struct bHYPRE_Hybrid__sepv*
bHYPRE_Hybrid__statics(void);

extern void bHYPRE_Hybrid__init(
  struct bHYPRE_Hybrid__object* self, void* ddata,
    struct sidl_BaseInterface__object ** _ex);
extern void bHYPRE_Hybrid__getEPVs(
  struct sidl_BaseInterface__epv **s_arg_epv__sidl_baseinterface,
  struct sidl_BaseInterface__epv **s_arg_epv_hooks__sidl_baseinterface,
  struct sidl_BaseClass__epv **s_arg_epv__sidl_baseclass,
    struct sidl_BaseClass__epv **s_arg_epv_hooks__sidl_baseclass,
  struct bHYPRE_Operator__epv **s_arg_epv__bhypre_operator,
  struct bHYPRE_Operator__epv **s_arg_epv_hooks__bhypre_operator,
  struct bHYPRE_Solver__epv **s_arg_epv__bhypre_solver,
  struct bHYPRE_Solver__epv **s_arg_epv_hooks__bhypre_solver,
  struct bHYPRE_Hybrid__epv **s_arg_epv__bhypre_hybrid,
    struct bHYPRE_Hybrid__epv **s_arg_epv_hooks__bhypre_hybrid);
  extern void bHYPRE_Hybrid__fini(
    struct bHYPRE_Hybrid__object* self,
      struct sidl_BaseInterface__object ** _ex);
  extern void bHYPRE_Hybrid__IOR_version(int32_t *major, int32_t *minor);

  struct bHYPRE_Hybrid__object* skel_bHYPRE_Hybrid_fconnect_bHYPRE_Hybrid(const 
    char* url, sidl_bool ar, struct sidl_BaseInterface__object **_ex);
  struct bHYPRE_Hybrid__object* skel_bHYPRE_Hybrid_fcast_bHYPRE_Hybrid(void *bi,
    struct sidl_BaseInterface__object **_ex);

  struct bHYPRE_MPICommunicator__object* 
    skel_bHYPRE_Hybrid_fconnect_bHYPRE_MPICommunicator(const char* url,
    sidl_bool ar, struct sidl_BaseInterface__object **_ex);
  struct bHYPRE_MPICommunicator__object* 
    skel_bHYPRE_Hybrid_fcast_bHYPRE_MPICommunicator(void *bi,
    struct sidl_BaseInterface__object **_ex);

  struct bHYPRE_Operator__object* 
    skel_bHYPRE_Hybrid_fconnect_bHYPRE_Operator(const char* url, sidl_bool ar,
    struct sidl_BaseInterface__object **_ex);
  struct bHYPRE_Operator__object* skel_bHYPRE_Hybrid_fcast_bHYPRE_Operator(void 
    *bi, struct sidl_BaseInterface__object **_ex);

  struct bHYPRE_PreconditionedSolver__object* 
    skel_bHYPRE_Hybrid_fconnect_bHYPRE_PreconditionedSolver(const char* url,
    sidl_bool ar, struct sidl_BaseInterface__object **_ex);
  struct bHYPRE_PreconditionedSolver__object* 
    skel_bHYPRE_Hybrid_fcast_bHYPRE_PreconditionedSolver(void *bi,
    struct sidl_BaseInterface__object **_ex);

  struct bHYPRE_Solver__object* skel_bHYPRE_Hybrid_fconnect_bHYPRE_Solver(const 
    char* url, sidl_bool ar, struct sidl_BaseInterface__object **_ex);
  struct bHYPRE_Solver__object* skel_bHYPRE_Hybrid_fcast_bHYPRE_Solver(void *bi,
    struct sidl_BaseInterface__object **_ex);

  struct bHYPRE_Vector__object* skel_bHYPRE_Hybrid_fconnect_bHYPRE_Vector(const 
    char* url, sidl_bool ar, struct sidl_BaseInterface__object **_ex);
  struct bHYPRE_Vector__object* skel_bHYPRE_Hybrid_fcast_bHYPRE_Vector(void *bi,
    struct sidl_BaseInterface__object **_ex);

  struct sidl_BaseClass__object* 
    skel_bHYPRE_Hybrid_fconnect_sidl_BaseClass(const char* url, sidl_bool ar,
    struct sidl_BaseInterface__object **_ex);
  struct sidl_BaseClass__object* skel_bHYPRE_Hybrid_fcast_sidl_BaseClass(void 
    *bi, struct sidl_BaseInterface__object **_ex);

  struct sidl_BaseInterface__object* 
    skel_bHYPRE_Hybrid_fconnect_sidl_BaseInterface(const char* url,
    sidl_bool ar, struct sidl_BaseInterface__object **_ex);
  struct sidl_BaseInterface__object* 
    skel_bHYPRE_Hybrid_fcast_sidl_BaseInterface(void *bi,
    struct sidl_BaseInterface__object **_ex);

  struct sidl_ClassInfo__object* 
    skel_bHYPRE_Hybrid_fconnect_sidl_ClassInfo(const char* url, sidl_bool ar,
    struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* skel_bHYPRE_Hybrid_fcast_sidl_ClassInfo(void 
    *bi, struct sidl_BaseInterface__object **_ex);

  struct sidl_RuntimeException__object* 
    skel_bHYPRE_Hybrid_fconnect_sidl_RuntimeException(const char* url,
    sidl_bool ar, struct sidl_BaseInterface__object **_ex);
  struct sidl_RuntimeException__object* 
    skel_bHYPRE_Hybrid_fcast_sidl_RuntimeException(void *bi,
    struct sidl_BaseInterface__object **_ex);

  struct bHYPRE_Hybrid__remote{
    int d_refcount;
    struct sidl_rmi_InstanceHandle__object *d_ih;
  };

  #ifdef __cplusplus
  }
  #endif
  #endif
