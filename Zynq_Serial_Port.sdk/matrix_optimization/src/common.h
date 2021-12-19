#ifndef COMMON_H
#define COMMON_H


#define A(i,j) a[(j) * lda + (i)]
#define B(i,j) b[(j) * ldb + (i)]
#define C(i,j) c[(j) * ldc + (i)]
#define X(i) x[ (i)*incx ]


struct strassen_struct{
    double num1;
    double num2;
    double num3;
    double num4;
};

struct strassen_struct_recursive{
    double c00;
    double c01;
    double c10;
    double c11;
};



double* strassen_rec(double *a, double* b, double *c, int lda, int ldb, int ldc)
{
//    if (lda < 16)
//    {
//        //
//    } else {
//        double * a11 = new double[lda * ldb / 4];
//        double * a12 = new double[lda * ldb / 4];
//        double * a21 = new double[lda * ldb / 4];
//        double * a22 = new double[lda * ldb / 4];
//        double * b11 = new double[lda * ldb / 4];
//        double * b12 = new double[lda * ldb / 4];
//        double * b21 = new double[lda * ldb / 4];
//        double * b22 = new double[lda * ldb / 4];

//        double *k1 = strassen_rec(a11 + a22, )

//    }


}

struct strassen_struct strassen(double *a, double* b, int lda, int ldb)
{
    double m1 = (A(0,0) + A(1,1)) * (B(0,0) + B(1,1));
    double m2 = (A(1,0) + A(1,1)) * B(0,0);
    double m3 = (B(0,1) - B(1,1)) * A(0,0);
    double m4 = (B(1,0) - B(0,0)) * A(1,1);
    double m5 = (A(0,0) + A(0,1)) * B(1,1);
    double m6 = (A(1,0) - A(0,0)) * (B(0,0) + B(0,1));
    double m7 = (A(0,1) - A(1,1)) * (B(1,0) + B(1,1));

    struct strassen_struct rets;
    rets.num1 = m1 + m4 - m5 + m7;
    rets.num2 = m3 + m5;
    rets.num3 = m2 + m4;
    rets.num4 = m1 + m3 - m2 + m6;
    return rets;
}


void AddDot( int k, double *x, int incx,  double *y, double *gamma )
{
    /* compute gamma := x' * y + gamma with vectors x and y of length n.

     Here x starts at location x with increment (stride) incx and y starts at location y and has (implicit) stride of 1.
  */

    int p;

    for ( p=0; p<k; p++ ){
        *gamma += X( p ) * y[ p ];
    }
}

void AddDot1x4( int k, double *a, int lda,  double *b, int ldb, double *c, int ldc )
{
    /* So, this routine computes four elements of C:

           C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ).

     Notice that this routine is called with c = C( i, j ) in the
     previous routine, so these are actually the elements

           C( i, j ), C( i, j+1 ), C( i, j+2 ), C( i, j+3 )

     in the original matrix C */

    AddDot( k, &A( 0, 0 ), lda, &B( 0, 0 ), &C( 0, 0 ) );
    AddDot( k, &A( 0, 0 ), lda, &B( 0, 1 ), &C( 0, 1 ) );
    AddDot( k, &A( 0, 0 ), lda, &B( 0, 2 ), &C( 0, 2 ) );
    AddDot( k, &A( 0, 0 ), lda, &B( 0, 3 ), &C( 0, 3 ) );
}

void AddDot1x4_5( int k, double *a, int lda,  double *b, int ldb, double *c, int ldc )
{
    /* So, this routine computes four elements of C:

           C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ).

     Notice that this routine is called with c = C( i, j ) in the
     previous routine, so these are actually the elements

           C( i, j ), C( i, j+1 ), C( i, j+2 ), C( i, j+3 )

     in the original matrix C */

    for (int p=0; p<k; p++ ){
        C( 0, 0 ) += A( 0, p ) * B( p, 0 );
        C( 0, 1 ) += A( 0, p ) * B( p, 1 );
        C( 0, 2 ) += A( 0, p ) * B( p, 2 );
        C( 0, 3 ) += A( 0, p ) * B( p, 3 );
    }
}


void AddDot1x4_6( int k, double *a, int lda,  double *b, int ldb, double *c, int ldc )
{
    /* So, this routine computes four elements of C:

           C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ).

     Notice that this routine is called with c = C( i, j ) in the
     previous routine, so these are actually the elements

           C( i, j ), C( i, j+1 ), C( i, j+2 ), C( i, j+3 )

     in the original matrix C.

     In this version, we accumulate in registers and put A( 0, p ) in a register */

    int p;
    register double
            /* hold contributions to
               C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ) */
            c_00_reg,   c_01_reg,   c_02_reg,   c_03_reg,
            /* holds A( 0, p ) */
            a_0p_reg;

    c_00_reg = 0.0;
    c_01_reg = 0.0;
    c_02_reg = 0.0;
    c_03_reg = 0.0;

    for ( p=0; p<k; p++ ){
        a_0p_reg = A( 0, p );

        c_00_reg += a_0p_reg * B( p, 0 );
        c_01_reg += a_0p_reg * B( p, 1 );
        c_02_reg += a_0p_reg * B( p, 2 );
        c_03_reg += a_0p_reg * B( p, 3 );
    }

    C( 0, 0 ) += c_00_reg;
    C( 0, 1 ) += c_01_reg;
    C( 0, 2 ) += c_02_reg;
    C( 0, 3 ) += c_03_reg;
}


void AddDot1x4_7( int k, double *a, int lda,  double *b, int ldb, double *c, int ldc )
{
    /* So, this routine computes four elements of C:

           C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ).

     Notice that this routine is called with c = C( i, j ) in the
     previous routine, so these are actually the elements

           C( i, j ), C( i, j+1 ), C( i, j+2 ), C( i, j+3 )

     in the original matrix C.

     In this version, we use pointer to track where in four columns of B we are */

    int p;
    register double
            /* hold contributions to
               C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ) */
            c_00_reg,   c_01_reg,   c_02_reg,   c_03_reg,
            /* holds A( 0, p ) */
            a_0p_reg;
    double
            /* Point to the current elements in the four columns of B */
            *bp0_pntr, *bp1_pntr, *bp2_pntr, *bp3_pntr;

    bp0_pntr = &B( 0, 0 );
    bp1_pntr = &B( 0, 1 );
    bp2_pntr = &B( 0, 2 );
    bp3_pntr = &B( 0, 3 );

    c_00_reg = 0.0;
    c_01_reg = 0.0;
    c_02_reg = 0.0;
    c_03_reg = 0.0;

    for ( p=0; p<k; p++ ){
        a_0p_reg = A( 0, p );

        c_00_reg += a_0p_reg * *bp0_pntr++;
        c_01_reg += a_0p_reg * *bp1_pntr++;
        c_02_reg += a_0p_reg * *bp2_pntr++;
        c_03_reg += a_0p_reg * *bp3_pntr++;
    }

    C( 0, 0 ) += c_00_reg;
    C( 0, 1 ) += c_01_reg;
    C( 0, 2 ) += c_02_reg;
    C( 0, 3 ) += c_03_reg;
}


void AddDot4x4_5( int k, double *a, int lda,  double *b, int ldb, double *c, int ldc )
{
    /* So, this routine computes four elements of C:

           C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ).

     Notice that this routine is called with c = C( i, j ) in the
     previous routine, so these are actually the elements

           C( i, j ), C( i, j+1 ), C( i, j+2 ), C( i, j+3 )

     in the original matrix C */

    for (int p=0; p<k; p++ ){
        C( 0, 0 ) += A( 0, p ) * B( p, 0 );
        C( 0, 1 ) += A( 0, p ) * B( p, 1 );
        C( 0, 2 ) += A( 0, p ) * B( p, 2 );
        C( 0, 3 ) += A( 0, p ) * B( p, 3 );

        C( 1, 0 ) += A( 1, p ) * B( p, 0 );
        C( 1, 1 ) += A( 1, p ) * B( p, 1 );
        C( 1, 2 ) += A( 1, p ) * B( p, 2 );
        C( 1, 3 ) += A( 1, p ) * B( p, 3 );

        C( 2, 0 ) += A( 2, p ) * B( p, 0 );
        C( 2, 1 ) += A( 2, p ) * B( p, 1 );
        C( 2, 2 ) += A( 2, p ) * B( p, 2 );
        C( 2, 3 ) += A( 2, p ) * B( p, 3 );

        C( 3, 0 ) += A( 3, p ) * B( p, 0 );
        C( 3, 1 ) += A( 3, p ) * B( p, 1 );
        C( 3, 2 ) += A( 3, p ) * B( p, 2 );
        C( 3, 3 ) += A( 3, p ) * B( p, 3 );
    }
}


void AddDot4x4_6( int k, double *a, int lda,  double *b, int ldb, double *c, int ldc )
{
    /* So, this routine computes four elements of C:

           C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ).

     Notice that this routine is called with c = C( i, j ) in the
     previous routine, so these are actually the elements

           C( i, j ), C( i, j+1 ), C( i, j+2 ), C( i, j+3 )

     in the original matrix C */

    register double
            /* hold contributions to
                 C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ) */
            c_00_reg,   c_01_reg,   c_02_reg,   c_03_reg,
            c_10_reg,   c_11_reg,   c_12_reg,   c_13_reg,
            c_20_reg,   c_21_reg,   c_22_reg,   c_23_reg,
            c_30_reg,   c_31_reg,   c_32_reg,   c_33_reg,
            /* holds A( 0, p ) */
            a_0p_reg,   a_1p_reg,   a_2p_reg,   a_3p_reg;

    c_00_reg = 0.0;
    c_01_reg = 0.0;
    c_02_reg = 0.0;
    c_03_reg = 0.0;

    c_10_reg = 0.0;
    c_11_reg = 0.0;
    c_12_reg = 0.0;
    c_13_reg = 0.0;

    c_20_reg = 0.0;
    c_21_reg = 0.0;
    c_22_reg = 0.0;
    c_23_reg = 0.0;

    c_30_reg = 0.0;
    c_31_reg = 0.0;
    c_32_reg = 0.0;
    c_33_reg = 0.0;


    for (int p=0; p<k; p++ ){
        a_0p_reg =  A( 0, p );
        a_1p_reg =  A( 1, p );
        a_2p_reg =  A( 2, p );
        a_3p_reg =  A( 3, p );

        c_00_reg += a_0p_reg * B( p, 0 );
        c_01_reg += a_0p_reg * B( p, 1 );
        c_02_reg += a_0p_reg * B( p, 2 );
        c_03_reg += a_0p_reg * B( p, 3 );

        c_10_reg += a_1p_reg * B( p, 0 );
        c_11_reg += a_1p_reg * B( p, 1 );
        c_12_reg += a_1p_reg * B( p, 2 );
        c_13_reg += a_1p_reg * B( p, 3 );

        c_20_reg += a_2p_reg * B( p, 0 );
        c_21_reg += a_2p_reg * B( p, 1 );
        c_22_reg += a_2p_reg * B( p, 2 );
        c_23_reg += a_2p_reg * B( p, 3 );

        c_30_reg += a_3p_reg * B( p, 0 );
        c_31_reg += a_3p_reg * B( p, 1 );
        c_32_reg += a_3p_reg * B( p, 2 );
        c_33_reg += a_3p_reg * B( p, 3 );
    }

    C( 0, 0 ) += c_00_reg;
    C( 0, 1 ) += c_01_reg;
    C( 0, 2 ) += c_02_reg;
    C( 0, 3 ) += c_03_reg;

    C( 1, 0 ) += c_10_reg;
    C( 1, 1 ) += c_11_reg;
    C( 1, 2 ) += c_12_reg;
    C( 1, 3 ) += c_13_reg;

    C( 2, 0 ) += c_20_reg;
    C( 2, 1 ) += c_21_reg;
    C( 2, 2 ) += c_22_reg;
    C( 2, 3 ) += c_23_reg;

    C( 3, 0 ) += c_30_reg;
    C( 3, 1 ) += c_31_reg;
    C( 3, 2 ) += c_32_reg;
    C( 3, 3 ) += c_33_reg;
}


void AddDot4x4_7( int k, double *a, int lda,  double *b, int ldb, double *c, int ldc )
{
    /* So, this routine computes four elements of C:

           C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ).

     Notice that this routine is called with c = C( i, j ) in the
     previous routine, so these are actually the elements

           C( i, j ), C( i, j+1 ), C( i, j+2 ), C( i, j+3 )

     in the original matrix C */

    register double
            /* hold contributions to
                 C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ) */
            c_00_reg,   c_01_reg,   c_02_reg,   c_03_reg,
            c_10_reg,   c_11_reg,   c_12_reg,   c_13_reg,
            c_20_reg,   c_21_reg,   c_22_reg,   c_23_reg,
            c_30_reg,   c_31_reg,   c_32_reg,   c_33_reg,
            /* holds A( 0, p ) */
            a_0p_reg,   a_1p_reg,   a_2p_reg,   a_3p_reg;

    double
            /* Point to the current elements in the four columns of B */
            *bp0_pntr, *bp1_pntr, *bp2_pntr, *bp3_pntr;

    bp0_pntr = &B( 0, 0 );
    bp1_pntr = &B( 0, 1 );
    bp2_pntr = &B( 0, 2 );
    bp3_pntr = &B( 0, 3 );

    c_00_reg = 0.0;
    c_01_reg = 0.0;
    c_02_reg = 0.0;
    c_03_reg = 0.0;

    c_10_reg = 0.0;
    c_11_reg = 0.0;
    c_12_reg = 0.0;
    c_13_reg = 0.0;

    c_20_reg = 0.0;
    c_21_reg = 0.0;
    c_22_reg = 0.0;
    c_23_reg = 0.0;

    c_30_reg = 0.0;
    c_31_reg = 0.0;
    c_32_reg = 0.0;
    c_33_reg = 0.0;

    for (int p=0; p<k; p++ ){
        a_0p_reg =  A( 0, p );
        a_1p_reg =  A( 1, p );
        a_2p_reg =  A( 2, p );
        a_3p_reg =  A( 3, p );

        c_00_reg += a_0p_reg * *bp0_pntr;
        c_01_reg += a_0p_reg * *bp1_pntr;
        c_02_reg += a_0p_reg * *bp2_pntr;
        c_03_reg += a_0p_reg * *bp3_pntr;

        c_10_reg += a_1p_reg * *bp0_pntr;
        c_11_reg += a_1p_reg * *bp1_pntr;
        c_12_reg += a_1p_reg * *bp2_pntr;
        c_13_reg += a_1p_reg * *bp3_pntr;

        c_20_reg += a_2p_reg * *bp0_pntr;
        c_21_reg += a_2p_reg * *bp1_pntr;
        c_22_reg += a_2p_reg * *bp2_pntr;
        c_23_reg += a_2p_reg * *bp3_pntr;

        c_30_reg += a_3p_reg * *bp0_pntr;
        c_31_reg += a_3p_reg * *bp1_pntr;
        c_32_reg += a_3p_reg * *bp2_pntr;
        c_33_reg += a_3p_reg * *bp3_pntr;

        bp0_pntr++;
        bp1_pntr++;
        bp2_pntr++;
        bp3_pntr++;
    }

    C( 0, 0 ) += c_00_reg;
    C( 0, 1 ) += c_01_reg;
    C( 0, 2 ) += c_02_reg;
    C( 0, 3 ) += c_03_reg;

    C( 1, 0 ) += c_10_reg;
    C( 1, 1 ) += c_11_reg;
    C( 1, 2 ) += c_12_reg;
    C( 1, 3 ) += c_13_reg;

    C( 2, 0 ) += c_20_reg;
    C( 2, 1 ) += c_21_reg;
    C( 2, 2 ) += c_22_reg;
    C( 2, 3 ) += c_23_reg;

    C( 3, 0 ) += c_30_reg;
    C( 3, 1 ) += c_31_reg;
    C( 3, 2 ) += c_32_reg;
    C( 3, 3 ) += c_33_reg;
}




void AddDot4x4_8( int k, double *a, int lda,  double *b, int ldb, double *c, int ldc )
{
    /* So, this routine computes four elements of C:

           C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ).

     Notice that this routine is called with c = C( i, j ) in the
     previous routine, so these are actually the elements

           C( i, j ), C( i, j+1 ), C( i, j+2 ), C( i, j+3 )

     in the original matrix C */

    register double
            /* hold contributions to
                 C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ) */
            c_00_reg,   c_01_reg,   c_02_reg,   c_03_reg,
            c_10_reg,   c_11_reg,   c_12_reg,   c_13_reg,
            c_20_reg,   c_21_reg,   c_22_reg,   c_23_reg,
            c_30_reg,   c_31_reg,   c_32_reg,   c_33_reg,
            /* holds A( 0, p ) */
            a_0p_reg,   a_1p_reg,   a_2p_reg,   a_3p_reg,
            /* holds B( p, 0 ) */
            b_p0_reg,   b_p1_reg,   b_p2_reg,   b_p3_reg;

    c_00_reg = 0.0;
    c_01_reg = 0.0;
    c_02_reg = 0.0;
    c_03_reg = 0.0;

    c_10_reg = 0.0;
    c_11_reg = 0.0;
    c_12_reg = 0.0;
    c_13_reg = 0.0;

    c_20_reg = 0.0;
    c_21_reg = 0.0;
    c_22_reg = 0.0;
    c_23_reg = 0.0;

    c_30_reg = 0.0;
    c_31_reg = 0.0;
    c_32_reg = 0.0;
    c_33_reg = 0.0;

    for (int p=0; p<k; p++ ){
        a_0p_reg =  A( 0, p );
        a_1p_reg =  A( 1, p );
        a_2p_reg =  A( 2, p );
        a_3p_reg =  A( 3, p );

        b_p0_reg =  B( p, 0 );
        b_p1_reg =  B( p, 1 );
        b_p2_reg =  B( p, 2 );
        b_p3_reg =  B( p, 3 );

        c_00_reg += a_0p_reg * b_p0_reg;
        c_01_reg += a_0p_reg * b_p1_reg;
        c_02_reg += a_0p_reg * b_p2_reg;
        c_03_reg += a_0p_reg * b_p3_reg;

        c_10_reg += a_1p_reg * b_p0_reg;
        c_11_reg += a_1p_reg * b_p1_reg;
        c_12_reg += a_1p_reg * b_p2_reg;
        c_13_reg += a_1p_reg * b_p3_reg;

        c_20_reg += a_2p_reg * b_p0_reg;
        c_21_reg += a_2p_reg * b_p1_reg;
        c_22_reg += a_2p_reg * b_p2_reg;
        c_23_reg += a_2p_reg * b_p3_reg;

        c_30_reg += a_3p_reg * b_p0_reg;
        c_31_reg += a_3p_reg * b_p1_reg;
        c_32_reg += a_3p_reg * b_p2_reg;
        c_33_reg += a_3p_reg * b_p3_reg;
    }

    C( 0, 0 ) += c_00_reg;
    C( 0, 1 ) += c_01_reg;
    C( 0, 2 ) += c_02_reg;
    C( 0, 3 ) += c_03_reg;

    C( 1, 0 ) += c_10_reg;
    C( 1, 1 ) += c_11_reg;
    C( 1, 2 ) += c_12_reg;
    C( 1, 3 ) += c_13_reg;

    C( 2, 0 ) += c_20_reg;
    C( 2, 1 ) += c_21_reg;
    C( 2, 2 ) += c_22_reg;
    C( 2, 3 ) += c_23_reg;

    C( 3, 0 ) += c_30_reg;
    C( 3, 1 ) += c_31_reg;
    C( 3, 2 ) += c_32_reg;
    C( 3, 3 ) += c_33_reg;
}


void cache_line_dot( int k, double *a, int lda,  double *b, int ldb, double *c, int ldc )
{
    for (int p=0; p<k; p++ ){
        C( 0, 0 ) += A( 0, p ) * B( p, 0 );
        C( 0, 1 ) += A( 0, p ) * B( p, 1 );
        C( 0, 2 ) += A( 0, p ) * B( p, 2 );
        C( 0, 3 ) += A( 0, p ) * B( p, 3 );
        C( 0, 4 ) += A( 0, p ) * B( p, 4 );
        C( 0, 5 ) += A( 0, p ) * B( p, 5 );
        C( 0, 6 ) += A( 0, p ) * B( p, 6 );
        C( 0, 7 ) += A( 0, p ) * B( p, 7 );

        C( 1, 0 ) += A( 1, p ) * B( p, 0 );
        C( 1, 1 ) += A( 1, p ) * B( p, 1 );
        C( 1, 2 ) += A( 1, p ) * B( p, 2 );
        C( 1, 3 ) += A( 1, p ) * B( p, 3 );
        C( 1, 4 ) += A( 1, p ) * B( p, 4 );
        C( 1, 5 ) += A( 1, p ) * B( p, 5 );
        C( 1, 6 ) += A( 1, p ) * B( p, 6 );
        C( 1, 7 ) += A( 1, p ) * B( p, 7 );

        C( 2, 0 ) += A( 2, p ) * B( p, 0 );
        C( 2, 1 ) += A( 2, p ) * B( p, 1 );
        C( 2, 2 ) += A( 2, p ) * B( p, 2 );
        C( 2, 3 ) += A( 2, p ) * B( p, 3 );
        C( 2, 4 ) += A( 2, p ) * B( p, 4 );
        C( 2, 5 ) += A( 2, p ) * B( p, 5 );
        C( 2, 6 ) += A( 2, p ) * B( p, 6 );
        C( 2, 7 ) += A( 2, p ) * B( p, 7 );

        C( 3, 0 ) += A( 3, p ) * B( p, 0 );
        C( 3, 1 ) += A( 3, p ) * B( p, 1 );
        C( 3, 2 ) += A( 3, p ) * B( p, 2 );
        C( 3, 3 ) += A( 3, p ) * B( p, 3 );
        C( 3, 4 ) += A( 3, p ) * B( p, 4 );
        C( 3, 5 ) += A( 3, p ) * B( p, 5 );
        C( 3, 6 ) += A( 3, p ) * B( p, 6 );
        C( 3, 7 ) += A( 3, p ) * B( p, 7 );

        C( 4, 0 ) += A( 4, p ) * B( p, 0 );
        C( 4, 1 ) += A( 4, p ) * B( p, 1 );
        C( 4, 2 ) += A( 4, p ) * B( p, 2 );
        C( 4, 3 ) += A( 4, p ) * B( p, 3 );
        C( 4, 4 ) += A( 4, p ) * B( p, 4 );
        C( 4, 5 ) += A( 4, p ) * B( p, 5 );
        C( 4, 6 ) += A( 4, p ) * B( p, 6 );
        C( 4, 7 ) += A( 4, p ) * B( p, 7 );

        C( 5, 0 ) += A( 5, p ) * B( p, 0 );
        C( 5, 1 ) += A( 5, p ) * B( p, 1 );
        C( 5, 2 ) += A( 5, p ) * B( p, 2 );
        C( 5, 3 ) += A( 5, p ) * B( p, 3 );
        C( 5, 4 ) += A( 5, p ) * B( p, 4 );
        C( 5, 5 ) += A( 5, p ) * B( p, 5 );
        C( 5, 6 ) += A( 5, p ) * B( p, 6 );
        C( 5, 7 ) += A( 5, p ) * B( p, 7 );

        C( 6, 0 ) += A( 6, p ) * B( p, 0 );
        C( 6, 1 ) += A( 6, p ) * B( p, 1 );
        C( 6, 2 ) += A( 6, p ) * B( p, 2 );
        C( 6, 3 ) += A( 6, p ) * B( p, 3 );
        C( 6, 4 ) += A( 6, p ) * B( p, 4 );
        C( 6, 5 ) += A( 6, p ) * B( p, 5 );
        C( 6, 6 ) += A( 6, p ) * B( p, 6 );
        C( 6, 7 ) += A( 6, p ) * B( p, 7 );

        C( 7, 0 ) += A( 7, p ) * B( p, 0 );
        C( 7, 1 ) += A( 7, p ) * B( p, 1 );
        C( 7, 2 ) += A( 7, p ) * B( p, 2 );
        C( 7, 3 ) += A( 7, p ) * B( p, 3 );
        C( 7, 4 ) += A( 7, p ) * B( p, 4 );
        C( 7, 5 ) += A( 7, p ) * B( p, 5 );
        C( 7, 6 ) += A( 7, p ) * B( p, 6 );
        C( 7, 7 ) += A( 7, p ) * B( p, 7 );
    }

}



#endif // COMMON_H
