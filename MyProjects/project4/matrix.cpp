#include "matrix.h"
#include <cfloat>
#include <cassert>
#include<cmath>
template<typename T>
Matrix<T>::Matrix(size_t rows,size_t cols):rows(rows),cols(cols),start(0),stride(cols),blob(rows*cols)
{

}

template<typename T>
Matrix<T>::Matrix(size_t rows,size_t cols,T value):rows(rows),cols(cols),start(0),stride(cols),blob(rows*cols)
{
	for(size_t i=0;i<rows*cols;i++)
	{
		blob.data[i]=value;
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other)=default;

template<typename T>
Matrix<T>::~Matrix()=default;

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> & other)
{
	if(this!=&other)
	{
		rows = other.rows;
		cols = other.cols;
		start = other.start;
		stride = other.stride;
		blob = other.blob;
	}
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
{
	assert(rows==other.rows&&cols==other.cols);
	Matrix res(rows,cols);
	for(size_t i=0;i<res.rows;i++)
	{
		for(size_t j=0;j<res.cols;j++)
		{
			res(i,j) = this->at(i,j)+other.at(i,j);
		}
	}
	return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const
{
	assert(rows==other.rows&&cols==other.cols);
	Matrix res(rows,cols);
	for(size_t i=0;i<res.rows;i++)
	{
		for(size_t j=0;j<res.cols;j++)
		{
			res(i,j) = this->at(i,j)-other.at(i,j);
		}
	}
	return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const
{
	assert(rows==other.rows&&cols==other.cols);
	Matrix res(rows,cols);
	for(size_t i=0;i<res.rows;i++)
	{
		for(size_t j=0;j<res.cols;j++)
		{
			res(i,j) = this->at(i,j)*other.at(i,j);
		}
	}
	return res;
}

template<typename T>
Matrix<T> Matrix<T>::matmul(const Matrix<T>& other) const
{
	assert(cols==other.rows);
	Matrix res(rows,other.cols);
	for(size_t i=0;i<res.rows;i++)
	{
		for(size_t j=0;j<res.cols;j++)
		{
			T tmp = 0;
			for(size_t k=0;k<rows;k++)
			{
				tmp+=this->at(i,k)*other.at(k,j);
			}
			res(i,j) = tmp;
		}
	}
	return res;
}

template<typename T>
Matrix<T> Matrix<T>::roi(size_t x,size_t y,size_t w,size_t h) const
{
	assert(x+w<=cols&&y+h<=rows);
	Matrix res(*this);
	res.start = start+y*stride+x;
	res.cols = w;
	res.rows = h;
	return res;
}

template<typename T>
void Matrix<T>::copyFrom(const Matrix& other)
{
	assert(rows==other.rows&&cols==other.cols);
	for(size_t i=0;i<other.rows;i++)
	{
		for(size_t j=0;j<other.cols;j++)
		{
			(*this)(i,j) = other.at(i,j);
		}
	}
}

template<typename T>
void Matrix<T>::copyTo(Matrix& other) const
{
	assert(rows==other.rows&&cols==other.cols);
	for(size_t i=0;i<other.rows;i++)
	{
		for(size_t j=0;j<other.cols;j++)
		{
			other(i,j) = this->at(i,j);
		}
	}
}

template<typename T>
Matrix<T> Matrix<T>::operator+=(const Matrix<T>& other)
{
	*this = (*this)+other;
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-=(const Matrix<T>& other)
{
	*this = (*this)-other;
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*=(const Matrix<T>& other)
{
	*this = (*this)*other;
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const T& other) const
{
	
	Matrix<T> res(rows,cols);
	for(size_t i=0;i<this->rows;i++)
	{
		for(size_t j=0;j<this->cols;j++)
		{
			res(i,j) = this->at(i,j)+other;
		}
	}
	return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T& other) const
{
	Matrix<T> res(rows,cols);
	for(size_t i=0;i<this->rows;i++)
	{
		for(size_t j=0;j<this->cols;j++)
		{
			res(i,j) = this->at(i,j)-other;
		}
	}
	return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& other) const
{
	
	Matrix<T> res(rows,cols);
	for(size_t i=0;i<this->rows;i++)
	{
		for(size_t j=0;j<this->cols;j++)
		{
			res(i,j) = this->at(i,j)*other;
		}
	}
	return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator+=(const T& other)
{
	*this = (*this)+other;
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-=(const T& other)
{
	*this = (*this)-other;
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*=(const T& other)
{
	*this = (*this)*other;
	return *this;
}

template<typename T>
bool Matrix<T>::operator==(const Matrix& other) const
{
	assert(rows==other.rows&&cols==other.cols);
	double diff = 0;
	Matrix<T> res(rows,cols);
	for(size_t i=0;i<this->rows;i++)
	{
		for(size_t j=0;j<this->cols;j++)
		{
			diff+=abs(this->at(i,j)-other.at(i,j));
		}
	}
	if(diff<DBL_EPSILON)
		return true;
	else
		return false;
}

template<typename T>
Matrix<T> Matrix<T>::operator-() const
{
	Matrix<T> res{cols,rows};
	res = (T)0-(const Matrix<T>)(*this);
	return res;
}

template<typename T>
T& Matrix<T>::operator()(size_t row,size_t col)
{
	assert(row<rows&&col<cols);
	return blob.data[start+row*stride+col];
}

template<typename T>
T& Matrix<T>::at(size_t row,size_t col) const
{
	assert(row<rows&&col<cols);
	return blob.data[start+row*stride+col];
}

template<typename T>
void Matrix<T>::print()
{
	cout<<*this<<endl;;
}

template<typename T>
Matrix<T> operator+(const T& a,const Matrix<T>& b)
{
	return b+a;
}

template<typename T>
Matrix<T> operator-(const T& a,const Matrix<T>& b)
{
	return -b+a;
}

template<typename T>
Matrix<T> operator*(const T& a,const Matrix<T>& b)
{
	return b*a;
}

template<typename T>
ostream& operator<<(ostream& os,const Matrix<T>& m)
{
	for(size_t i=0;i<m.rows;i++)
	{
		for(size_t j=0;j<m.cols;j++)
		{
			os<<m.at(i,j)<<" ";	
		}
		os<<endl;
	}
	return os;
}

template class Matrix<unsigned char>;
template class Matrix<short>;
template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;
