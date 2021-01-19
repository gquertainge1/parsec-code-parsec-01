#ifndef MYLIB_H
#define MYLIB_H

#define SIZE_I 960
#define SIZE_J 1280
#define BLOCK_SIZE 16

#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <cuda_runtime.h>

using namespace std;

using namespace cv;

//---------------------normal---------------------

Mat normal(Mat frame);

//---------------------noirBlanc------------------

Mat noirBlanc(Mat frame);

//---------------------seuillage------------------

Mat seuillage(Mat frame);
//__global__ Mat seuillageGPU(Mat frame);

//---------------------contour--------------------

Mat contour(Mat frame);

//---------------------autres---------------------

Mat seuillageGPU( Mat in);



#endif
