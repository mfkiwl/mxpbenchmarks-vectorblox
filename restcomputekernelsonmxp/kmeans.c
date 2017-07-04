// kmeans

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
//#include "vbx_test.h"
//#include "vbx_types.h"
#include "vectorblox_mxp_lin.h" 
#define N 256
#define M 16384
#define ops 23
#define MXP                                                                     

int main(){
#ifdef MXP
    VectorBlox_MXP_Initialize("mxp0","cma");
#else
    printf("MXP Disabled, APP is running entirely on ARM\n");
#endif
vbx_mxp_print_params();
vbx_timestamp_t time_start,time_stop;

int32_t i;
int8_t *i_3 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_14 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_5 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_16 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_7 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_18 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_9 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_20 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_11 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_22 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_35 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_46 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_47 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_58 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_59 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *i_70 = vbx_shared_malloc(N*M*sizeof(int8_t));
int8_t *res = vbx_shared_malloc(N*M*sizeof(int8_t));

vbx_byte_t *vi_3 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_14 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_5 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_16 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_7 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_18 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_9 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_20 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_11 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_22 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_35 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_46 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_47 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_58 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_59 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vi_70 = vbx_sp_malloc(M*sizeof(vbx_byte_t));


vbx_byte_t *vtemp1 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vtemp2 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vtemp3 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vtemp4 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vtemp5 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vtemp6 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vtemp7 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vtemp8 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vt1 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vt2 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vt3 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vt4 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vt5 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vt6 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vt7 = vbx_sp_malloc(M*sizeof(vbx_byte_t));
vbx_byte_t *vres = vbx_sp_malloc(M*sizeof(vbx_byte_t));

vbx_dcache_flush_all();

vbx_set_vl(M);
for(i=0;i<M*N;i++){
i_3[i]=3;
}

for(i=0;i<M*N;i++){
i_14[i]=1;
}

for(i=0;i<M*N;i++){
i_5[i]=3;
}

for(i=0;i<M*N;i++){
i_16[i]=1;
}

for(i=0;i<M*N;i++){
i_7[i]=3;
}

for(i=0;i<M*N;i++){
i_18[i]=1;
}

for(i=0;i<M*N;i++){
i_9[i]=3;
}
for(i=0;i<M*N;i++){
i_20[i]=1;
}
for(i=0;i<M*N;i++){
i_11[i]=3;
}
for(i=0;i<M*N;i++){
i_22[i]=1;
}

for(i=0;i<M*N;i++){
i_35[i]=3;
}
for(i=0;i<M*N;i++){
i_46[i]=1;
}

for(i=0;i<M*N;i++){
i_47[i]=3;
}

for(i=0;i<M*N;i++){
i_58[i]=1;
}

for(i=0;i<M*N;i++){
i_59[i]=3;
}

for(i=0;i<M*N;i++){
i_70[i]=1;
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
vbx_dma_to_vector( vi_3,i_3+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_14,i_14+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_5,i_5+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_16,i_16+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_7,i_7+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_18,i_18+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_9,i_9+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_20,i_20+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_11,i_11+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_22,i_22+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_35,i_35+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_46,i_46+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_47,i_47+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_58,i_58+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_59,i_59+i,M*sizeof(vbx_byte_t));
vbx_dma_to_vector( vi_70,i_70+i,M*sizeof(vbx_byte_t));

vbx( VVB,VSUB,vtemp1,vi_3,vi_14);
vbx( VVB,VSUB,vtemp2,vi_5,vi_16);
vbx( VVB,VSUB,vtemp3,vi_7,vi_18);
vbx( VVB,VSUB,vtemp4,vi_9,vi_20);
vbx( VVB,VSUB,vtemp5,vi_11,vi_22);
vbx( VVB,VSUB,vtemp6,vi_35,vi_46);
vbx( VVB,VSUB,vtemp7,vi_47,vi_58);
vbx( VVB,VSUB,vtemp8,vi_59,vi_70);

//int temp_1 = in3 - in14
//int temp_2 = in5 - in16
//int temp_3 = in7 - in18
//int temp_4 = in9 - in20
//int temp_5 = in11 - in22
//int temp_6 = in35 - in46
//int temp_7 = in47 - in58
//int temp_8 = in59 - in70

vbx( VVB,VMUL,vt1,vtemp1,vtemp1);
vbx( VVB,VMUL,vt2,vtemp2,vtemp2);
vbx( VVB,VADD,vt2,vt1,vt2);
vbx( VVB,VMUL,vt3,vtemp3,vtemp3);
vbx( VVB,VADD,vt3,vt2,vt3);
vbx( VVB,VMUL,vt4,vtemp4,vtemp4);
vbx( VVB,VADD,vt4,vt3,vt4);
vbx( VVB,VMUL,vt5,vtemp5,vtemp5);
vbx( VVB,VADD,vt5,vt4,vt5);
vbx( VVB,VMUL,vt6,vtemp6,vtemp6);
vbx( VVB,VADD,vt6,vt5,vt6);
vbx( VVB,VMUL,vt7,vtemp7,vtemp7);
vbx( VVB,VADD,vt7,vt6,vt7);

//int t_1 = temp_1*temp_1
//int t_2 = temp_2*temp_2 + t_1
//int t_3 = temp_3*temp_3 + t_2
//int t_4 = temp_4*temp_4 + t_3
//int t_5 = temp_5*temp_5 + t_4
//int t_6 = temp_6*temp_6 + t_5
//int t_7 = temp_7*temp_7 + t_6


vbx( VVB,VMUL,vres,vtemp8,vtemp8);
vbx( VVB,VADD,vres,vres,vt7);

//temp_8*temp_8 + t_7

vbx_dma_to_host(res+i,vres,M*sizeof(vbx_byte_t));
vbx_sync();

}
time_stop = vbx_timestamp();
/*
for(i=0;i<N*M;i++){
printf("The %d sample is: %d\n",i+1,res[i]);
}
*/
vbx_timestamp_t cycles = time_stop - time_start;
double seconds = ((double) cycles) / ((double) vbx_timestamp_freq());
printf("Maximum Throughput on MXP for chebyshev kernel in (Gops/sec) is ->%g Gops/sec\n",(N*M*ops)/(seconds*pow(10,9))); 

vbx_shared_free(i_3);
vbx_shared_free(i_14);
vbx_shared_free(i_5);
vbx_shared_free(i_16);
vbx_shared_free(i_7);
vbx_shared_free(i_18);
vbx_shared_free(i_9);
vbx_shared_free(i_20);
vbx_shared_free(i_11);
vbx_shared_free(i_22);
vbx_shared_free(i_35);
vbx_shared_free(i_46);
vbx_shared_free(i_47);
vbx_shared_free(i_58);
vbx_shared_free(i_59);
vbx_shared_free(i_70);
vbx_shared_free(res);
vbx_sp_free();
return 0;
}
