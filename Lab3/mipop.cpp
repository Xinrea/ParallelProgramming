//Author: Xinrea
//Date: 2018/7/8

#include "mipop.h"
#include <omp.h>
#include <cstdio>
#include <cstring>

int *MIPerosion(int *img, int *se, int img_width, int img_height, int se_width, int se_height){
    if(se_width%2 == 0|| se_height%2 == 0)return img; // SE is not standard
    if(se_width > img_width|| se_height > img_height)return img; // Can't do anything
    int total = (img_width-se_width)*(img_height-se_height); // total pixels needed to be processed
    int *output = new int[img_width*img_height];
    memcpy(output,img,img_height*img_width*sizeof(int));
    omp_set_num_threads(4);
    double begin = omp_get_wtime();
    #pragma omp parallel for
    for(int i = 0; i <= img_height-se_height; i++){
        for(int k = 0; k <= img_width-se_width; k++){
            int x = k+se_width/2;
            int y = i+se_height/2;
            int compares = se_width*se_height;
            bool isMiss = false;
            for(int i = 0; i < compares; i++){ // row: i%args->se_width, colomn: i/args->se_width
                int row = i%se_width;
                int colomn = i/se_width;
                int px = x-se_width/2+colomn;
                int py = y-se_height/2+row;
                if(se[i]==1&&img[px+py*img_width]==0)isMiss = true;
            }
            if(isMiss){
                output[x+y*img_width] = 0;
            } else {
                output[x+y*img_width] = img[x+y*img_width];
            }
        }
    }
    double end = omp_get_wtime();
    printf("Total time: %f\n",end-begin);
    return output;
}