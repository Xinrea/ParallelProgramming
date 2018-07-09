//Author: Xinrea
//Date: 2018/7/8

#include "mipop.h"
#include <pthread.h>
#include <vector>
#include <cstdio>
#include <cstring>
using std::vector;
struct kernel_arg{
    int x;
    int y;
    int *img;
    int img_width;
    int img_height;
    int *se;
    int se_width;
    int se_height;
    int *output;
};

void* kernel(void *arg){
    kernel_arg *args = (kernel_arg*)arg;
    int compares = args->se_width*args->se_height;
    bool isMiss = false;
    for(int i = 0; i < compares; i++){ // row: i%args->se_width, colomn: i/args->se_width
        int row = i%args->se_width;
        int colomn = i/args->se_width;
        int px = args->x-args->se_width/2+colomn;
        int py = args->y-args->se_height/2+row;
        if(args->se[i]==1&&args->img[px+py*args->img_width]==0)isMiss = true;
    }
    printf("x: %d y: %d (%dX%d)\n", args->x, args->y,args->img_width,args->img_height);
    if(isMiss){
        args->output[args->x+args->y*args->img_width] = 0;
        printf("Miss, set %d to zero\n",args->x+args->y*args->img_width);
    } else {
        args->output[args->x+args->y*args->img_width] = args->img[args->x+args->y*args->img_width];
    }
    printf("Result: %d\n",args->output[args->x+args->y*args->img_width]);
    delete args;
}

int *MIPerosion(int *img, int *se, int img_width, int img_height, int se_width, int se_height){
    if(se_width%2 == 0|| se_height%2 == 0)return img; // SE is not standard
    if(se_width > img_width|| se_height > img_height)return img; // Can't do anything
    int total = (img_width-se_width)*(img_height-se_height); // total pixels needed to be processed
    int *output = new int[img_width*img_height];
    memcpy(output,img,img_height*img_width*sizeof(int));
    vector<pthread_t> threads;
    for(int i = 0; i <= img_height-se_height; i++){
        for(int k = 0; k <= img_width-se_width; k++){
            kernel_arg *args = new kernel_arg;
            args->x = k+se_width/2;
            args->y = i+se_height/2;
            args->img = img;  
            args->img_width = img_width;
            args->img_height = img_height;
            args->se = se;
            args->se_width = se_width;
            args->se_height = se_height;
            args->output = output;
            pthread_t tid;
            pthread_create(&tid,NULL,kernel,(void*)args);
            threads.push_back(tid);
        }
    }
    for(pthread_t i : threads){
        pthread_join(i,NULL);
    }
    return output;
}