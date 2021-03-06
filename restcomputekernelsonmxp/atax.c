//atax.c benchmark implemented on the vbx 

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
#define N 1
#define M 1

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

int8_t *A_0 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *A_1 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *A_2 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *A_3 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *A_4 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *A_5 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *A_6 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *A_7 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *A_8 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *x_0 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *x_1 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *x_2 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *y_0 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *y_1 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *y_2 = vbx_shared_malloc(N*M*sizeof(int8_t));

vbx_byte_t *vA_0 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vA_1 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vA_2 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vA_3 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vA_4 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vA_5 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vA_6 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vA_7 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vA_8 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vx_0 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vx_1 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vx_2 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vy_0 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vy_1 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vy_2 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vtemp1 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vtemp2 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vtemp3 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vtemp4 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vtemp5 = vbx_sp_malloc(M*sizeof(vbx_byte_t));


vbx_dcache_flush_all();

vbx_set_vl(M);
for(i=0;i<M*N;i++){
A_0[i]=2;
}

for(i=0;i<M*N;i++){
A_1[i]=2;
}

for(i=0;i<M*N;i++){
A_2[i]=2;
}

for(i=0;i<M*N;i++){
A_3[i]=2;
}

for(i=0;i<M*N;i++){
A_4[i]=2;
}

for(i=0;i<M*N;i++){
A_5[i]=2;
}

for(i=0;i<M*N;i++){
A_6[i]=2;
}


for(i=0;i<M*N;i++){
A_7[i]=2;
}


for(i=0;i<M*N;i++){
A_8[i]=2;
}


for(i=0;i<M*N;i++){
x_0[i]=2;
}

for(i=0;i<M*N;i++){
x_1[i]=2;
}


for(i=0;i<M*N;i++){
x_2[i]=2;
}

/*
for(i=0;i<M*N;i++){
printf("%d |",x_t[i]);
}
printf("\n");
*/

vbx_timestamp_start();
time_start = vbx_timestamp();
for(i=0;i<M*N;i=i+M)
{
vbx_dma_to_vector( vA_0,A_0+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vA_1,A_1+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vA_2,A_2+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vA_3,A_3+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vA_4,A_4+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vA_5,A_5+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vA_6,A_6+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vA_7,A_7+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vA_8,A_8+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vx_0,x_0+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vx_1,x_1+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vx_2,x_2+i,M*sizeof(vbx_byte_t));

vbx( VVB,VMUL,vy_0,vA_0,vx_0);
vbx( VVB,VMUL,vtemp1,vA_1,vx_1);
vbx( VVB,VMUL,vtemp2,vA_2,vx_2);
vbx( VVB,VADD,vtemp2,vtemp1,vtemp2);
vbx( VVB,VADD,vy_0,vtemp2,vy_0);
vbx( VVB,VMUL,vy_0,vA_0,vy_0);

vbx( VVB,VMUL,vtemp1,vA_3,vx_0);
vbx( VVB,VMUL,vtemp2,vA_4,vx_1);
vbx( VVB,VMUL,vy_1,vA_5,vx_2);
vbx( VVB,VADD,vtemp2,vtemp1,vtemp2);
vbx( VVB,VADD,vy_1,vtemp2,vy_1);
vbx( VVB,VMUL,vy_1,vA_3,vy_1);

vbx( VVB,VMUL,vtemp1,vA_6,vx_0);
vbx( VVB,VMUL,vtemp2,vA_7,vx_1);
vbx( VVB,VMUL,vy_2,vA_8,vx_2);
vbx( VVB,VADD,vtemp2,vtemp1,vtemp2);
vbx( VVB,VADD,vy_2,vtemp2,vy_2);
vbx( VVB,VMUL,vy_2,vA_6,vy_2);

vbx( VVB,VADD,vy_1,vy_2,vy_1);
vbx( VVB,VADD,vy_0,vy_1,vy_0);
// y[0] = (A[0] * (A[0] * x[0] + A[1] * x[1] + A[2] * x[2]) 
//       + A[3] * (A[3] * x[0] + A[4] * x[1] + A[5] * x[2]) 
//       + A[6] * (A[6] * x[0] + A[7] * x[1] + A[8] * x[2]))



vbx( VVB,VMUL,vtemp3,vA_0,vx_0);
vbx( VVB,VMUL,vtemp1,vA_1,vx_1);
vbx( VVB,VMUL,vtemp2,vA_2,vx_2);
vbx( VVB,VADD,vtemp2,vtemp1,vtemp2);
vbx( VVB,VADD,vtemp3,vtemp2,vtemp3);
vbx( VVB,VMUL,vtemp3,vA_1,vtemp3);

vbx( VVB,VMUL,vtemp1,vA_3,vx_0);
vbx( VVB,VMUL,vtemp2,vA_4,vx_1);
vbx( VVB,VMUL,vy_1,vA_5,vx_2);
vbx( VVB,VADD,vtemp2,vtemp1,vtemp2);
vbx( VVB,VADD,vy_1,vtemp2,vy_1);
vbx( VVB,VMUL,vy_1,vA_4,vy_1);

vbx( VVB,VMUL,vtemp1,vA_6,vx_0);
vbx( VVB,VMUL,vtemp2,vA_7,vx_1);
vbx( VVB,VMUL,vy_2,vA_8,vx_2);
vbx( VVB,VADD,vtemp2,vtemp1,vtemp2);
vbx( VVB,VADD,vy_2,vtemp2,vy_2);
vbx( VVB,VMUL,vy_2,vA_7,vy_2);

vbx( VVB,VADD,vy_1,vy_2,vy_1);
vbx( VVB,VADD,vy_1,vy_1,vtemp3);


// y[1] = (A[1] * (A[0] * x[0] + A[1] * x[1] + A[2] * x[2]) 
//       + A[4] * (A[3] * x[0] + A[4] * x[1] + A[5] * x[2]) 
//       + A[7] * (A[6] * x[0] + A[7] * x[1] + A[8] * x[2]))


vbx( VVB,VMUL,vtemp4,vA_0,vx_0);
vbx( VVB,VMUL,vtemp1,vA_1,vx_1);
vbx( VVB,VMUL,vtemp2,vA_2,vx_2);
vbx( VVB,VADD,vtemp2,vtemp1,vtemp2);
vbx( VVB,VADD,vtemp4,vtemp2,vtemp4);
vbx( VVB,VMUL,vtemp4,vA_2,vtemp4);

vbx( VVB,VMUL,vtemp1,vA_3,vx_0);
vbx( VVB,VMUL,vtemp2,vA_4,vx_1);
vbx( VVB,VMUL,vtemp5,vA_5,vx_2);
vbx( VVB,VADD,vtemp2,vtemp1,vtemp2);
vbx( VVB,VADD,vtemp5,vtemp2,vtemp5);
vbx( VVB,VMUL,vtemp5,vA_5,vtemp5);

vbx( VVB,VMUL,vtemp1,vA_6,vx_0);
vbx( VVB,VMUL,vtemp2,vA_7,vx_1);
vbx( VVB,VMUL,vy_2,vA_8,vx_2);
vbx( VVB,VADD,vtemp2,vtemp1,vtemp2);
vbx( VVB,VADD,vy_2,vtemp2,vy_2);
vbx( VVB,VMUL,vy_2,vA_8,vy_2);

vbx( VVB,VADD,vtemp5,vy_2,vtemp5);
vbx( VVB,VADD,vy_2,vtemp5,vtemp4);


// y[2] = (A[2] * (A[0] * x[0] + A[1] * x[1] + A[2] * x[2]) 
//       + A[5] * (A[3] * x[0] + A[4] * x[1] + A[5] * x[2]) 
//       + A[8] * (A[6] * x[0] + A[7] * x[1] + A[8] * x[2]))



//vbx_dma_to_host(y_0+i,vy_0,M*sizeof(vbx_byte_t));
//vbx_dma_to_host(y_1+i,vy_1,M*sizeof(vbx_byte_t));
vbx_dma_to_host(y_2+i,vy_2,M*sizeof(vbx_byte_t));
vbx_sync();
}
time_stop = vbx_timestamp();
/*
for(i=0;i<N*M;i++){
printf("The %d sample is: %d\n",i+1,res[i]);
}
*/
//printf("The sample is: %d\n",y_0[0]);
//printf("The sample is: %d\n",y_1[0]);
printf("The sample is: %d\n",y_2[0]);

seconds=vbx_print_scalar_time( time_start, time_stop );
printf("Took timer ticks -> %g s\n" , seconds);
vbx_shared_free(A_0);
vbx_shared_free(A_1);
vbx_shared_free(A_2);
vbx_shared_free(A_3);
vbx_shared_free(A_4);
vbx_shared_free(A_5);
vbx_shared_free(A_6);
vbx_shared_free(A_7);
vbx_shared_free(A_8);
vbx_shared_free(x_0);
vbx_shared_free(x_1);
vbx_shared_free(x_2);
vbx_shared_free(y_0);
vbx_shared_free(y_1);
vbx_shared_free(y_2);

vbx_sp_free();
return 0;
}

