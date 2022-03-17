#ifndef MATMUL_H_
#define MATMUL_H_
#include "mat.h"
Mat multiply(const Mat* a,const Mat* b);
Mat multiply_fast(const Mat* a,const Mat* b);
#endif