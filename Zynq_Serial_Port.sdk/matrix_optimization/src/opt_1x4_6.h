#ifndef OPT_1X4_6_H
#define OPT_1X4_6_H

#include "common.h"

double* opt_1x4_6(int row_a, int col_a, int row_b, int col_b)
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

//    auto start = std::chrono::high_resolution_clock::now();

    for ( j=0; j<col_b; j+=4 ){        /* Loop over the columns of C, unrolled by 4 */
        for ( i=0; i<row_a; i+=1 ){        /* Loop over the rows of C */
            /* Update the C( i,j ) with the inner product of the ith row of A
         and the jth column of B */

            AddDot1x4_6(col_a, &A( i,0 ), lda, &B( 0,j ), ldb, &C( i,j ), ldc );
        }
    }

//    auto end = std::chrono::high_resolution_clock::now();

//    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start ).count();
//    std::cout << " opt_1x4_6: " << std::fixed  << duration << " ms" << std::endl;
    free(a);
    free(b);
    return c;
}


#endif // OPT_1X4_6_H
