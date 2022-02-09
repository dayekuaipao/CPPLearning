#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "matrix.h"
MyMatrix allocMatrix( int row, int col ) {
    struct MyMatrix result;
    result.row = row;
    result.col = col;
    result.mat = (float*)malloc( sizeof(float)*row*col );

    return result;
}

void freeMatrix( struct MyMatrix& matrix ) {
    free(matrix.mat);
}

MyMatrix readMatFromFile( const char* filename ) {
    FILE* file = fopen( filename, "r" );
    int row, col;
    fscanf(file, "%d%d", &row, &col );
    MyMatrix result = allocMatrix(row, col);
    for( int i = 0; i < row; ++ i )
        for( int j = 0; j < col; ++ j )
            fscanf(file, "%f", &result(i,j));
    fclose(file);
    return result;
}

void writeMatToFile( MyMatrix& mat, const char* filename ) {
    FILE* file = fopen( filename, "w" );
    fprintf(file, "%zu %zu\n", mat.row, mat.col );
    for( int i = 0; i < mat.row; ++ i ) {
        for( int j = 0; j < mat.col; ++ j )
            fprintf(file, " %f", mat(i,j));
        fprintf(file, "\n");
    }
    fclose(file);
}

MyMatrix multiply( MyMatrix& a, MyMatrix& b ) {
    return multiplyByCol(a,b);
}

MyMatrix multiplyByCol( MyMatrix& a, MyMatrix& b ) {
    MyMatrix result = allocMatrix( a.row, b.col );
    memset( result.mat, 0, sizeof(float)*result.length() );
    if( a.col != b.row )
        return result;
    for( int j = 0; j < b.col; j ++ )
        for( int i = 0; i < a.row; i ++ )
            for( int k = 0; k < a.col; k ++ )
                result(i,j) += a(i,k) * b(k,j);
    return result;
}


MyMatrix multiplyByRow( MyMatrix& a, MyMatrix& b ) {
    MyMatrix result = allocMatrix( a.row, b.col );
    memset( result.mat, 0, sizeof(float)*result.length() );
    if( a.col != b.row )
        return result;
    for( int i = 0; i < a.row; i ++ )
        for( int j = 0; j < b.col; j ++ )
            for( int k = 0; k < a.col; k ++ )
                result(i,j) += a(i,k) * b(k,j);
    return result;
}

MyMatrix randomMatrix(int row, int col, int seed) {
    std::srand(seed);
    MyMatrix mat = allocMatrix(2048,2048);
    for(int i=0;i<2048;i++)
    {
        for(int j=0;j<2048;j++)
        {
            mat(i,j) = std::rand()*1.0/std::rand();
        }
    }
    return mat;
}

MyMatrix add( MyMatrix& a, MyMatrix& b ) {
    return addByCol(a,b);
}


MyMatrix addByRow(MyMatrix& a,MyMatrix& b)
{
    MyMatrix result = allocMatrix( a.row, b.col );
    memset( result.mat, 0, sizeof(float)*result.length() );
    if(a.row!=b.row||a.col!=b.col)
        return result;
    for( int i = 0; i < a.row; i ++ )
        for( int j = 0; j < b.col; j ++ )
            result(i,j) = a(i,j)+b(i,j);
    return result;
}

MyMatrix addByCol(MyMatrix& a,MyMatrix& b)
{
    MyMatrix result = allocMatrix( a.row, b.col );
    memset( result.mat, 0, sizeof(float)*result.length() );
    if(a.row!=b.row||a.col!=b.col)
        return result;
    for( int j = 0; j < b.col; j ++ )
        for( int i = 0; i < a.row; i ++ )
            result(i,j) = a(i,j)+b(i,j);
    return result;
}

MyMatrix sub(MyMatrix& a,MyMatrix& b)
{
    MyMatrix result = allocMatrix( a.row, b.col );
    memset( result.mat, 0, sizeof(float)*result.length() );
    if(a.row!=b.row||a.col!=b.col)
        return result;
    for( int i = 0; i < a.row; i ++ )
        for( int j = 0; j < b.col; j ++ )
            result(i,j) = a(i,j)-b(i,j);
    return result;
}