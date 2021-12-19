/*
 * image.h
 *
 *  Created on: Aug 30, 2021
 *      Author: hp
 */

#ifndef SRC_IMAGE_H_
#define SRC_IMAGE_H_

#include <stdio.h>


typedef unsigned char pval;

struct imageStruct;
typedef struct imageStruct Image;

Image *allocateImage();
void freeImage(Image * image);

int readImage(FILE *f, Image *image);
int writeImage(FILE *f, Image * image);


int setPixelRGB(Image∗ image, int row, int col, pval r, pval g, pval b);
int setPixelGray(Image∗ image, int row, int col, pval v);
pixel getPixelRGB(Image∗ image, int row, int col);
pval getPixelGray(Image∗ image, int row, int col);

#endif /* SRC_IMAGE_H_ */
