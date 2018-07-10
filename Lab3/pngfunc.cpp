#include "pngfunc.h"

unsigned char* ArrayToRGB(int *a, int width, int height){
    unsigned char *rgb = new unsigned char[width*height*3];
    unsigned char *p = rgb;
    for(int i = 0; i < height; i++){
        for(int k = 0; k < width; k++){
            if(*(a+i*width+k)){
                *rgb++ = 0;
                *rgb++ = 0;
                *rgb++ = 0;
            } else {
                *rgb++ = 255;
                *rgb++ = 255;
                *rgb++ = 255;
            }
        }
    }
    return p;
}

int *RGBToArray(unsigned char *rgb, int width, int height){
    int total = width*height;
    int *a = new int[total];
    int *p = a;
    for(int i = 0; i < total; i++){
        if(*(rgb+3*i)){
            *a++ = 0;
        } else {
            *a++ = 1;
        }
    }
    return p;
}

int *FileToArray(FILE* fp, int& width, int& height){
    fseek(fp,0,SEEK_END);
    int fsize = ftell(fp);
    rewind(fp);
    unsigned char *buffer = new unsigned char[fsize];
    fread(buffer,1,fsize,fp);
    width = buffer[19];
    height = buffer[23];
    int *res = new int[width*height];
    for(int i = 0; i < height; i++){
        for(int k = 0; k < width; k++){
            res[i*width+k] = !(buffer[49+i*(width*3+1+5)+3*k]/255);
        }
    }
    return res;
}
