#include <stdio.h>
#include <time.h>
#include "mat.h"
#include "matmul.h"
#define TEST_TIMES 100
int main(int argc, char const *argv[])
{   
    Mat a;
    Mat b;

    int m1 = 700;
    int k1 = 800;
    int n1 = 500;
    a = createMat(m1,k1);
    b = createMat(k1,n1);
    for(int i=0;i<k1;i++)
    {
        for(int j=0;j<m1;j++)
            a.data[j*k1+i] = j*k1+i;
        for(int j=0;j<n1;j++)
            b.data[i*n1+j] = i*n1+j;
    }
    clock_t t1 = clock();
    for(int i=0;i<TEST_TIMES;i++)
    {
    	Mat c;
    	c = matmul(&a,&b);
    	deleteMat(&c);
    }
    clock_t t2 = clock();
    printf("time = %f\n",(DATA_TYPE)(t2-t1)/CLOCKS_PER_SEC);
    for(int i=0;i<TEST_TIMES;i++)
    {
        Mat c;
        c = matmul_fast(&a,&b);
        deleteMat(&c);
    }
    clock_t t3 = clock();
    printf("time = %f\n",(DATA_TYPE)(t3-t2)/CLOCKS_PER_SEC);
    // Mat c;
    // c = multiply(&a,&b);
    // printMat(&c);
    // deleteMat(&c);
    // c = multiply_fast(&a,&b);
    // printMat(&c);
    // deleteMat(&c);  

}