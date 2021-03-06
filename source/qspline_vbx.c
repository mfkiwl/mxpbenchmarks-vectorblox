// qspline.c benchmark implemented in mxp
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
#define N 4096
#define M 1024
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
int32_t *a_t = vbx_shared_malloc(N*M*sizeof(int32_t));
int32_t *b_t = vbx_shared_malloc(N*M*sizeof(int32_t));
int32_t *q_t = vbx_shared_malloc(N*M*sizeof(int32_t));
int32_t *u_t = vbx_shared_malloc(N*M*sizeof(int32_t));
int32_t *v_t = vbx_shared_malloc(N*M*sizeof(int32_t));
int32_t *w_t = vbx_shared_malloc(N*M*sizeof(int32_t));
int32_t *z_t = vbx_shared_malloc(N*M*sizeof(int32_t));
int32_t *res = vbx_shared_malloc(N*M*sizeof(int32_t));

vbx_word_t *va = vbx_sp_malloc(M*sizeof(vbx_word_t));
vbx_word_t *vb = vbx_sp_malloc(M*sizeof(vbx_word_t));
vbx_word_t *vq = vbx_sp_malloc(M*sizeof(vbx_word_t));
vbx_word_t *vu = vbx_sp_malloc(M*sizeof(vbx_word_t));
vbx_word_t *vv = vbx_sp_malloc(M*sizeof(vbx_word_t));
vbx_word_t *vw = vbx_sp_malloc(M*sizeof(vbx_word_t));
vbx_word_t *vz = vbx_sp_malloc(M*sizeof(vbx_word_t));
vbx_word_t *vtemp = vbx_sp_malloc(M*sizeof(vbx_word_t));
vbx_word_t *vtemp1 = vbx_sp_malloc(M*sizeof(vbx_word_t));
vbx_word_t *vres = vbx_sp_malloc(M*sizeof(vbx_word_t));

vbx_dcache_flush_all();
vbx_set_vl(M);
for(i=0;i<M*N;i++){
a_t[i]=1;
b_t[i]=1;
q_t[i]=1;
u_t[i]=1;
v_t[i]=1;
w_t[i]=1;
z_t[i]=1;
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
vbx_dma_to_vector( va,a_t+i,M*sizeof(vbx_word_t));
vbx_dma_to_vector( vb,b_t+i,M*sizeof(vbx_word_t));
vbx_dma_to_vector( vq,q_t+i,M*sizeof(vbx_word_t));
vbx_dma_to_vector( vu,u_t+i,M*sizeof(vbx_word_t));
vbx_dma_to_vector( vv,v_t+i,M*sizeof(vbx_word_t));
vbx_dma_to_vector( vw,w_t+i,M*sizeof(vbx_word_t));
vbx_dma_to_vector( vz,z_t+i,M*sizeof(vbx_word_t));
vbx_dma_to_vector( vres,b_t+i,M*sizeof(vbx_word_t));

//temp3
vbx( VVW,VMUL,vz,vz,vu);
vbx( VVW,VMUL,vz,vz,vu);
vbx( VVW,VMUL,vz,vz,vu);

//temp_3 = z*u*u*u;
//temp6

vbx( VVW,VMUL,vq,vq,vv);
vbx( VVW,VMUL,vq,vq,vv);
vbx( VVW,VMUL,vq,vq,vv);

//v*v*v*q



//temp7 or temp8


vbx( VVW,VMUL,vtemp,vv,vu);
//u*v



//temp 11
vbx( VVW,VMUL,va,va,vu);
vbx( SVW,VMUL,va,4,va);
vbx( VVW,VMUL,va,va,vu);
vbx( VVW,VMUL,va,va,vu);
vbx( VVW,VMUL,va,va,vv);

//v*u*u*4*a*u


//temp14

vbx( VVW,VMUL,vtemp1,vtemp,vw);
vbx( SVW,VMUL,vtemp1,4,vtemp1);
vbx( VVW,VMUL,vtemp1,vtemp1,vv);
vbx( VVW,VMUL,vtemp1,vtemp1,vv);

//v*v*4*w*u*v

vbx( VVW,VMUL,vz,vz,vu);
vbx( VVW,VADD,vz,vz,va);
vbx( VVW,VADD,vz,vz,vtemp1);
vbx( VVW,VMUL,vq,vq,vv);
vbx( VVW,VADD,vz,vz,vq);
vbx( VVW,VMUL,vres,vres,vtemp);
vbx( VVW,VMUL,vres,vres,vtemp);
vbx( SVW,VMUL,vres,6,vres);
vbx( VVW,VADD,vres,vres,vz);

vbx_dma_to_host(res+i,vres,M*sizeof(vbx_word_t));
vbx_sync();

}
time_stop = vbx_timestamp();
/*
for(i=0;i<N*M;i++){
printf("The %d sample is: %d\n",i+1,res[i]);
}
*/

printf("The sample is: %d %d\n",res[0],res[1]);

seconds=vbx_print_scalar_time( time_start, time_stop );
printf("Took timer ticks -> %g s\n" , seconds);
vbx_shared_free(a_t);
vbx_shared_free(b_t);
vbx_shared_free(q_t);
vbx_shared_free(u_t);
vbx_shared_free(v_t);
vbx_shared_free(w_t);
vbx_shared_free(z_t);
vbx_shared_free(res);
vbx_sp_free();
return 0;
}
