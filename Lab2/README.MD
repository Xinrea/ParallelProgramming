## Lab2

Parallel Implementation of Morphological Image Processing operation using pthread

## Contents

Using `pthread` to complete Morphological Image Processing operation

About Morphological Image Processing: 

https://www.cs.auckland.ac.nz/courses/compsci773s1c/lectures/ImageProcessing-html/topic4.htm

`MIP_pthread.cpp`: processing image

`SEcreator.cpp`: create structuring elements

SEcreator can generate png pictures and save them to dir `StructuringElements`. 

MIP_pthread will put output images to dir `Output`.

### operations:

`erosion`: shrink image regions

`dilation`: grow image regions

`opening`: structured removal of image region boundary pixels

`closing`: structured filling in of image region boundary pixels

`hit and miss transform`: image pattern matching and marking

`Thinning`: structured erosion using image pattern matching

`Thickening`: structured dilation using image pattern matching

`Skeletonization/Medial Axis Transform`: finding skeletons of binary regions