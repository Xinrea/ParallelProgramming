//Author: Xinrea
//Date: 2018/7/5
//Basic Sample of using CUDA

#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <cstdio>

cudaError_t addData(int size,int a[],int b[],int c[]);

__global__ void addKernel(int dev[],int size){
    int i = threadIdx.x;
    dev[2*size+i] = dev[i]+dev[size+i];
}

int main(int argc, char const *argv[])
{
    int size = 3;
    int a[3] = {1,2,3};
    int b[3] = {4,5,6};
    int c[3] = {0};
    cudaError_t res;
    res = addData(size,a,b,c);
    if(res != cudaSuccess){
        fprintf(stderr,"addData failed\n");
        return -1;
    }
    printf("%d %d %d\n",c[0],c[1],c[2]);
    res = cudaDeviceReset();
    if(res != cudaSuccess){
        fprintf(stderr,"cudaDeviceReset failed\n");
        return -1;
    }
    return 0;
}

cudaError_t addData(int size,int a[],int b[],int c[]){
    cudaError_t res;
    int *dev;
    do{
        res = cudaSetDevice(0);
        if (res != cudaSuccess) {
            fprintf(stderr, "cudaSetDevice failed\n");
            break;
        }
        res = cudaMalloc((void**)&dev,3*size*sizeof(int));
        if(res != cudaSuccess){
            fprintf(stderr,"cudaMalloc failed\n");
            break;
        }
        res = cudaMemcpy(dev,a,size*sizeof(int),cudaMemcpyHostToDevice);
        if(res != cudaSuccess){
            fprintf(stderr,"cudaMemcpy a failed\n");
            break;
        }
        res = cudaMemcpy(dev+size,b,size*sizeof(int),cudaMemcpyHostToDevice);
        if(res != cudaSuccess){
            fprintf(stderr,"cudaMemcpy b failed\n");
            break;
        }
        addKernel<<<1,size>>>(dev,size);
        res = cudaGetLastError();
        if(res != cudaSuccess){
            fprintf(stderr,"addData failed\n");
            break;
        }
        cudaDeviceSynchronize();
        res = cudaMemcpy(c,dev+2*size,size*sizeof(int),cudaMemcpyDeviceToHost);
        if(res != cudaSuccess){
            fprintf(stderr,"cudaMemcpy c failed\n");
            break;
        }
    } while(0);
    cudaFree(dev);
    return res;
}
