//Author: Xinrea
//Date: 2018/7/5

#include "svpng.inc"
#include "pngfunc.h"
#include "mipop.h"
#include <cstring>
#include <cstdio>
/* Basic processing:
File -(FileToArray)> Array -(MIP)> Array -(ArrayToRGB)> RGB -(svpng)> File */

int main(int argc, char const *argv[])
{
    //image to be processed
    printf("Input Filename: ");
    char infilename[30];
    scanf("%s",infilename);
    char in[40] = "Input/";
    strcat(in,infilename);
    //structuring elements
    printf("Input SE: ");
    char SEfilename[30];
    scanf("%s",SEfilename);
    char se[40] = "StructuringElements/";
    strcat(se,SEfilename);
    char outfile[40] = "Output/";
    strcat(outfile,infilename);
    strcat(outfile,"_erosion.png");

    FILE *fpin = fopen(in,"rb");
    int width, height;
    int *inArray = FileToArray(fpin, width, height);

    FILE *fpse = fopen(se,"rb");
    int se_width,se_height;
    int *seArray = FileToArray(fpse, se_width, se_height);

    int *out = MIPerosion(inArray, seArray, width, height, se_width, se_height);
    unsigned char* outRGB = ArrayToRGB(out,width,height);

    FILE *fpout = fopen(outfile,"wb");
    svpng(fpout,width,height,outRGB,0);
    fclose(fpse);
    fclose(fpin);
    fclose(fpout);
    return 0;
}