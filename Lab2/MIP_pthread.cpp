//Author: Xinrea
//Date: 2018/7/5

#include "svpng.inc"
#include <cstdio>

unsigned char* ArrayToRGB(int a[], int width, int height);
int *RGBToArray(unsigned char rgb[], int width, int height);
int *FileToArray(FILE* fp, int& width, int& height);

/* Basic processing:
File -(FileToArray)> Array -(MIP)> Array -(ArrayToRGB)> RGB -(svpng)> File */

int main(int argc, char const *argv[])
{
    unsigned char rgb[5 * 5 * 3], *p = rgb;
    unsigned x, y;
    FILE *fp = fopen("rgb.png", "wb");
    for (y = 0; y < 5; y++)
        for (x = 0; x < 5; x++) {
            if(y==2||x==2){ /* white */
                *p++ = 255;    /* R */
                *p++ = 255;    /* G */
                *p++ = 255;    /* B */
            }
            else { /* black */
                *p++ = 0;    /* R */
                *p++ = 0;    /* G */
                *p++ = 0;    /* B */
            }
        }
    svpng(fp, 5, 5, rgb, 0);
    fclose(fp);
    return 0;
}

unsigned char* ArrayToRGB(int a[], int width, int height){

}

int *RGBToArray(unsigned char rgb[], int width, int height){

}

int *FileToArray(FILE* fp, int& width, int& height){

}
