#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "matrix.h"
int main() {

    MyMatrix tmpMat1 = randomMatrix(2048,2048);
    MyMatrix tmpMat2 = randomMatrix(2048,2048);

    writeMatToFile(tmpMat1,"./data/2048_1.txt");
    writeMatToFile(tmpMat2,"./data/2048_2.txt");

    freeMatrix(tmpMat1);
    freeMatrix(tmpMat2);

    MyMatrix mat1 = readMatFromFile( "./data/2048_1.txt" );
    MyMatrix mat2 = readMatFromFile( "./data/2048_2.txt" );

    time_t t1 = time(NULL);
    MyMatrix res = multiplyByCol( mat1, mat2 );
    time_t t2 = time(NULL);

    double elasped = difftime(t2, t1);
    printf("Calculation multiplyByCol used %lf second(s).\n", elasped);
    writeMatToFile( res, "./data/2048_3.txt" );

    freeMatrix(res);

    t1 = time(NULL);
    res = multiplyByRow( mat1, mat2 );
    t2 = time(NULL);

    elasped = difftime(t2, t1);
    printf("Calculation multiplyByRow used %lf second(s).\n", elasped);

    writeMatToFile( res, "./data/2048_4.txt" );

    freeMatrix(mat1);
    freeMatrix(mat2);
    freeMatrix(res);

    mat1 = randomMatrix(1000000,1000);
    mat2 = randomMatrix(1000000,1000);
    t1 = time(NULL);
    res = addByRow( mat1, mat2 );
    t2 = time(NULL);

    elasped = difftime(t2, t1);
    printf("Calculation addByRow used %lf second(s).\n", elasped);

    t1 = time(NULL);
    res = addByCol( mat1, mat2 );
    t2 = time(NULL);

    elasped = difftime(t2, t1);
    printf("Calculation addByCol used %lf second(s).\n", elasped);

    freeMatrix(mat1);
    freeMatrix(mat2);
    freeMatrix(res);

    return 0;
}
