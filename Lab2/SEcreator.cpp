//Author: Xinrea
//Date: 2018/7/5
//Tool program for creating structuring elements

#include "svpng.inc"
#include "pngfunc.h"
#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
    printf("Please Input File Name: ");
    char filename[20];
    scanf("%s",filename);
    printf("Please Input Width and Height: ");
    int width, height;
    scanf("%d %d", &width, &height);
    int *a = new int[width*height];
    for(int i = 0; i < height; i++){
        for(int k = 0; k < width; k++){
            scanf("%d",&a[i*width+k]);
        }
    }
    unsigned char *img = ArrayToRGB(a,width,height);
    char fullname[40] = "StructuringElements/";
    strcat(fullname,filename);
    FILE *fp = fopen(fullname,"wb");
    svpng(fp,width,height,img,0);
    fclose(fp);
    return 0;
}
