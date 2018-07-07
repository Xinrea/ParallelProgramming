//Author: Xinrea
//Date: 2018/7/5

#include "svpng.inc"
#include "pngfunc.h"
#include <cstdio>
/* Basic processing:
File -(FileToArray)> Array -(MIP)> Array -(ArrayToRGB)> RGB -(svpng)> File */

int main(int argc, char const *argv[])
{
    int array[6][6] = {{0,1,1,1,1,0},{0,1,0,1,0,1},{0},{0},{0},{0}};
    /* test ArrayToRGB */
    unsigned char *rgb = ArrayToRGB((int*)array,6,6);
    /* test RGBToArray */
    int *a = RGBToArray(rgb,6,6);
    for(int i = 0; i < 36; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    FILE *fp = fopen("rgb.png", "wb");
    svpng(fp, 6, 6, rgb, 0);
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