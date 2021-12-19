#define A(i,j) a[ (j)*lda + (i) ]
#define B(i,j) b[ (j)*ldb + (i) ]
#define C(i,j) c[ (j)*ldc + (i) ]

/* Routine for computing C = A * B + C */

#include "common.h"

double* opt_1(int row_a, int col_a, int row_b, int col_b)
{
        double *a =  malloc(row_a* col_a * sizeof(double));
        double *b =  malloc(row_b* col_b * sizeof(double));
        double *c =  malloc(row_a* col_b * sizeof(double));
        int lda = row_a;
        int ldb = row_b;
        int ldc = row_a;
        int i, j;

        for (int i = 0; i < row_a * col_a; i++)
            a[i] = (double) i+1;

        for (int i = 0 ; i < row_a * col_b; i++)
            b[i] = (double)-i-1;

        for (int i = 0 ; i < row_a * col_b; i++)
            c[i] = 0.0;

//  auto start = std::chrono::high_resolution_clock::now();
  for ( j=0; j<col_b; j+=1 ){        /* Loop over the columns of C */
    for ( i=0; i<row_a; i+=1 ){        /* Loop over the rows of C */
      /* Update the C( i,j ) with the inner product of the ith row of A
     and the jth column of B */

      AddDot( col_a, &A( i,0 ), lda, &B( 0,j ), &C( i,j ) );
    }
  }
//  auto end = std::chrono::high_resolution_clock::now();

//  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start ).count();
//  std::cout << " opt1: " << std::fixed  << duration << " ms" << std::endl;
  free(a);
  free(b);
  return c;
}


/* Create macro to let X( i ) equal the ith element of x */


