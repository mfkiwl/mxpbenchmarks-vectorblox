// chebyshev.c benchmark on mxp

// Refer to the kernel_benchmarks.png for the DAG expression of the Kernel benchmark( Snap taken from Dr Abhishek Kumar Jain Throughput Oriented FPGA Overlays Using DSP Blocks thesis) 

#include <stdio.h>                                                              
#include <stdlib.h>
#include <string.h> 
#include <sys/types.h>
#include <sys/time.h>                                                           
#include <sys/resource.h>                                                       
#include <fcntl.h>
#include <unistd.h> 
#include <inttypes.h>
#include <errno.h>
#include <math.h>                                                               
#include "vbx.h"
#include "vbx_port.h" 
#include "vbx_common.h"
#include "vbx_test.h"
#include "vbx_types.h"
#include "vectorblox_mxp_lin.h" 
#define N 512
#define M 16384
#define MXP                                                                     

int main(){
#ifdef MXP
    VectorBlox_MXP_Initialize("mxp0","cma");
#else
    printf("MXP Disabled, APP is running entirely on ARM\n");
#endif
vbx_mxp_print_params();
vbx_timestamp_t time_start,time_stop;

double seconds;
int32_t i;
int32_t *x_t = vbx_shared_malloc(M*N*sizeof(int32_t));
vbx_word_t *vx = vbx_sp_malloc(M*sizeof(vbx_word_t));
vbx_word_t *vres = vbx_sp_malloc(M*sizeof(vbx_word_t));
vbx_dcache_flush_all();
vbx_set_vl(M);
for(i=0;i<M*N;i++){
x_t[i]=2;
}
/*
for(i=0;i<M*N;i++){
printf("%d |",x_t[i]);
}
printf("\n");
*/
vbx_timestamp_start();
time_start = vbx_timestamp();
for(i=0;i<M*N;i=i+M){
vbx_dma_to_vector( vx,x_t+i,M*sizeof(vbx_word_t));
vbx_dma_to_vector( vres,x_t+i,M*sizeof(vbx_word_t));

vbx( SVW,VMUL,vres,16,vres);
vbx( VVW,VMUL,vres,vx,vres);
vbx( SVW,VADD,vres,-20,vres);
//temp*x-20

vbx( VVW,VMUL,vres,vx,vres);
vbx( VVW,VMUL,vres,vx,vres);
//x*(temp*x-20)*x

vbx( SVW,VADD,vres,5,vres);
//x*(temp*x-20)*x+5

vbx( VVW,VMUL,vres,vx,vres );
//(x*(x*(temp*x-20)*x+5))
vbx_dma_to_host(x_t+i,vres,M*sizeof(vbx_word_t));
vbx_sync();
}
time_stop = vbx_timestamp();

/*for(i=0;i<N*M;i++){
printf("The %d sample is: %d\n",i+1,x_t[i]);
}
*/
seconds=vbx_print_scalar_time( time_start, time_stop );
printf("Took timer ticks -> %g s\n" , seconds);
vbx_shared_free(x_t);
vbx_sp_free();
return 0;
}
