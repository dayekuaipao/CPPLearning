#ifndef MATRIX_H_
#define MATRIX_H_
#include <bits/c++config.h>
#include <cstddef>
#include <iostream>
#include "blob.h"
using namespace::std;

template<typename T>
class Matrix{
public:
	size_t cols;
	size_t rows;
	Matrix(size_t cols,size_t rows);
	Matrix(size_t cols,size_t rows,T value);
	Matrix(const Matrix& other);
	~Matrix();

	Matrix& operator=(const Matrix& other);
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	Matrix operator+=(const Matrix& other);
	Matrix operator-=(const Matrix& other);
	Matrix operator*=(const Matrix& other);

	Matrix operator+(const T& other) const;
	Matrix operator-(const T& other) const;
	Matrix operator*(const T& other) const;
	Matrix operator+=(const T& other);
	Matrix operator-=(const T& other);
	Matrix operator*=(const T& other);

	bool operator==(const Matrix& other) const;

	Matrix operator-() const;
	T& operator()(size_t row,size_t col);
	T& at(size_t row,size_t col) const ;
	Matrix matmul(const Matrix& other) const;
	Matrix roi(size_t x,size_t y,size_t w,size_t h) const;

	void copyFrom(const Matrix& other);
	void copyTo(Matrix& other) const;
	
	template<typename T1>
	friend Matrix<T1> operator+(const T1& a,const Matrix<T1>& b);
	template<typename T1>
	friend Matrix<T1> operator-(const T1& a,const Matrix<T1>& b);
	template<typename T1>
	friend Matrix<T1> operator*(const T1& a,const Matrix<T1>& b);
	template<typename T1>
	friend ostream& operator<<(ostream& os,const Matrix<T1>& m);
	
	void print();

private:
	size_t start;
	size_t stride;
	Blob<T> blob;
};


typedef Matrix<double> Mat;
typedef Matrix<double> Matd;
typedef Matrix<float> Matf;
typedef Matrix<int> Mati;
#endif