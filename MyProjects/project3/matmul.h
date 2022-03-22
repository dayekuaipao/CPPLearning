#ifndef MATMUL_H_
#define MATMUL_H_
#include "mat.h"
Mat matmul(const Mat* a,const Mat* b);
Mat matmul_fast(const Mat* a,const Mat* b);
#endif