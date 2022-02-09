#ifndef MATRIX_H
#define MATRIX_H

struct MyMatrix
{
    float* mat;
    size_t row;
    size_t col;
    float& operator()(int r,int c)
    {
        return mat[r*col+c];
    }
    size_t length()
    {
        return row*col;
    }
};
MyMatrix allocMatrix( int row, int col );
void freeMatrix( struct MyMatrix& matrix );
MyMatrix readMatFromFile( const char* filename );
void writeMatToFile( MyMatrix& mat, const char* filename );
MyMatrix multiply( MyMatrix& a, MyMatrix& b );
MyMatrix multiplyByCol( MyMatrix& a, MyMatrix& b );
MyMatrix multiplyByRow( MyMatrix& a, MyMatrix& b );
MyMatrix randomMatrix(int row, int col, int seed=100);
MyMatrix add(MyMatrix& a,MyMatrix& b);
MyMatrix addByRow(MyMatrix& a,MyMatrix& b);
MyMatrix addByCol(MyMatrix& a,MyMatrix& b);
MyMatrix sub(MyMatrix& a,MyMatrix& b);

#endif