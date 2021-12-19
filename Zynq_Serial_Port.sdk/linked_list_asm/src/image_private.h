/*
 * image_private.h
 *
 *  Created on: Aug 30, 2021
 *      Author: hp
 */

#ifndef SRC_IMAGE_PRIVATE_H_
#define SRC_IMAGE_PRIVATE_H_

#include <image.h>

typedef struct {
	pval r,g,b;
} Pixel;



struct imageStruct {
	int rows;
	int cols;
	// number of columns in the image
	Pixel ∗ pixels; // array of pixel data
};


#endif /* SRC_IMAGE_PRIVATE_H_ */
