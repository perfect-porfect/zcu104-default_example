#ifndef NATIVE_MATMUL_H
#define NATIVE_MATMUL_H

#include "xtime_l.h"

double* native_matmul(int row_a, int col_a, int row_b, int col_b, bool save_file)
{
	int rowA = row_a;
	int colA = col_a;
	int rowB = row_b;
	int colB = col_b;
	int rowC = row_a;
	int colC = col_b;
	double sum = 0;

	double *a =  malloc(row_a * col_a * sizeof(double));
	double *b =  malloc(row_b * col_b * sizeof(double));
	double *c =  malloc(row_a * col_b * sizeof(double));

	int i, j;
	for (i = 0; i < row_a * col_a; i++)
		a[i] = (double)i+1;

	for (i = 0 ; i < row_b * col_b; i++)
		b[i] = (double)-i-1;

	for (i = 0 ; i < row_a * col_b; i++)
		c[i] = 0.0;
	XTime tStart, tEnd;

	XTime_GetTime(&tStart);
	for (int row = 0; row < rowA; row++)
	{
		for (int col = 0; col < colB; col++)
		{
			sum = 0;
			for (int k = 0; k < colA; k++)
			{
				int a_index = (row * colA) + k ;
				int b_index = (k * colB) + col;
				sum = sum + a[a_index] * b[b_index];
			}
			c[(row * colA) + col] = sum;
		}
	}
	XTime_GetTime(&tEnd);
	double elapsed = 1.0 * (tEnd - tStart) / (COUNTS_PER_SECOND/1000000);
	printf("native: time : %.2f us.\n", elapsed);

	//Free each sub-array
    free(a);
    free(b);
    return c;

}
#endif // NATIVE_MATMUL_H
