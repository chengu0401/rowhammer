#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wcast-qual"
#define __NV_CUBIN_HANDLE_STORAGE__ static
#if !defined(__CUDA_INCLUDE_COMPILER_INTERNAL_HEADERS__)
#define __CUDA_INCLUDE_COMPILER_INTERNAL_HEADERS__
#endif
#include "crt/host_runtime.h"
#include "cudahammer_test.fatbin.c"
extern void __device_stub__Z7kernel1PPiiiS_ii(int **, int, int, int *, int, int);
extern void __device_stub__Z7kernel2Pii(int *, int);
static void __nv_cudaEntityRegisterCallback(void **);
static void __sti____cudaRegisterAll(void) __attribute__((__constructor__));
void __device_stub__Z7kernel1PPiiiS_ii(int **__par0, int __par1, int __par2, int *__par3, int __par4, int __par5){__cudaLaunchPrologue(6);__cudaSetupArgSimple(__par0, 0UL);__cudaSetupArgSimple(__par1, 8UL);__cudaSetupArgSimple(__par2, 12UL);__cudaSetupArgSimple(__par3, 16UL);__cudaSetupArgSimple(__par4, 24UL);__cudaSetupArgSimple(__par5, 28UL);__cudaLaunch(((char *)((void ( *)(int **, int, int, int *, int, int))kernel1)));}
# 9 "cudahammer_test.cu"
void kernel1( int **__cuda_0,int __cuda_1,int __cuda_2,int *__cuda_3,int __cuda_4,int __cuda_5)
# 9 "cudahammer_test.cu"
{__device_stub__Z7kernel1PPiiiS_ii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5);




}
# 1 "cudahammer_test.cudafe1.stub.c"
void __device_stub__Z7kernel2Pii( int *__par0,  int __par1) {  __cudaLaunchPrologue(2); __cudaSetupArgSimple(__par0, 0UL); __cudaSetupArgSimple(__par1, 8UL); __cudaLaunch(((char *)((void ( *)(int *, int))kernel2))); }
# 16 "cudahammer_test.cu"
void kernel2( int *__cuda_0,int __cuda_1)
# 16 "cudahammer_test.cu"
{__device_stub__Z7kernel2Pii( __cuda_0,__cuda_1);



}
# 1 "cudahammer_test.cudafe1.stub.c"
static void __nv_cudaEntityRegisterCallback( void **__T0) {  __nv_dummy_param_ref(__T0); __nv_save_fatbinhandle_for_managed_rt(__T0); __cudaRegisterEntry(__T0, ((void ( *)(int *, int))kernel2), _Z7kernel2Pii, (-1)); __cudaRegisterEntry(__T0, ((void ( *)(int **, int, int, int *, int, int))kernel1), _Z7kernel1PPiiiS_ii, (-1)); }
static void __sti____cudaRegisterAll(void) {  __cudaRegisterBinary(__nv_cudaEntityRegisterCallback);  }

#pragma GCC diagnostic pop
