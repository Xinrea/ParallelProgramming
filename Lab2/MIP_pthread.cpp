//Author: Xinrea
//Date: 2018/7/5

#include "svpng.inc"
#include <cstdio>

unsigned char* ArrayToRGB(int *a, int width, int height);
int *RGBToArray(unsigned char *rgb, int width, int height);
int *FileToArray(FILE* fp, int& width, int& height);

/* Basic processing:
File -(FileToArray)> Array -(MIP)> Array -(ArrayToRGB)> RGB -(svpng)> File */

int main(int argc, char const *argv[])
{
    int array[5][5] = {{0,1,1,1,1},{0,1,0,1,0},{0},{0},{0}};
    /* test ArrayToRGB */
    unsigned char *rgb = ArrayToRGB((int*)array,5,5);
    /* test RGBToArray */
    int *a = RGBToArray(rgb,5,5);
    for(int i = 0; i < 25; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    FILE *fp = fopen("rgb.png", "wb");
    svpng(fp, 5, 5, rgb, 0);
    fclose(fp);

    fp = fopen("rgb.png","rb");
    int width,height;
    a = FileToArray(fp,width,height);
    printf("w: %d, h: %d\n",width,height);
    for(int i = 0; i < width*height; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    fclose(fp);
    return 0;
}

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
