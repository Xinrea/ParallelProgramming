//Author: Xinrea
//Date: 2018/7/7

#pragma once
#include <cstdio>
unsigned char* ArrayToRGB(int *a, int width, int height);
int *RGBToArray(unsigned char *rgb, int width, int height);
int *FileToArray(FILE* fp, int& width, int& height);