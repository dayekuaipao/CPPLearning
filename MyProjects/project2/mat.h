#ifndef MAT_H_
#define MAT_H_
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <assert.h>

typedef float DATA_TYPE;

#define MAX_SIZE 10000*10000
#define MAX_LENGTH 100000

typedef struct _Mat
{
    size_t rows;
    size_t cols;
    DATA_TYPE* data;
} Mat;

DATA_TYPE getElement(const Mat* mat,size_t row,size_t col);
DATA_TYPE* getElementPointer(Mat* mat,size_t row,size_t col);
const DATA_TYPE* getConstElementPointer(const Mat* mat,size_t row,size_t col);
Mat createMat(size_t rows,size_t cols);
void deleteMat(Mat* mat);
void copyMat(const Mat* a,Mat* b);
void printMat(const Mat* mat);
Mat readFromFile(const char* path);
void saveToFile(const char* path,const Mat* mat);
Mat multiply(const Mat* a,const Mat* b);
#endif