#include <cstddef>
#include <iostream>
#include <ostream>
using namespace::std;
template<class T>
class Matrix{
public:
	size_t cols;
	size_t rows;
	T * data;
	Matrix(size_t cols,size_t rows);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator=(const Matrix& other);
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	Matrix operator+=(const Matrix& other);
	Matrix operator-=(const Matrix& other);
	Matrix operator+(const T& other) const;
	Matrix operator-(const T& other) const;
	Matrix operator*(const T& other) const;
	Matrix operator+=(const T& other);
	Matrix operator-=(const T& other);
	Matrix operator-() const;
	T operator()(size_t row,size_t col);
	T& operator()(size_t row,size_t col) const;
	template <typename T1>
	friend Matrix<T1> operator+(const T1& a,const Matrix<T1>& b);
	template <typename T1>
	friend Matrix<T1> operator-(const T1& a,const Matrix<T1>& b);
	template <typename T1>
	friend Matrix<T1> operator*(const T1& a,const Matrix<T1>& b);
	template <typename T1>
	friend ostream& operator<<(ostream& os,const Matrix<T1>& m);
	void print(){cout<<*this;}
private:
	size_t* ref_count;
};

template<class T>
Matrix<T>::Matrix(size_t cols,size_t rows):cols(cols),rows(rows)
{
	data = new T[cols*rows];
	ref_count = new size_t(1);
	cout<<"constrctor, ref_count = "<<(*ref_count)<<endl;
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& other):cols(other.cols),rows(other.rows),data(other.data),ref_count(other.ref_count)
{
	++(*ref_count);
	cout<<"copy constrctor, ref_count = "<<(*ref_count)<<endl;
}

template<class T>
Matrix<T>::~Matrix()
{
	cout<<"destrctor, ref_count = "<<(*ref_count)<<endl;
	if(--(*ref_count)==0)
	{
		delete[] data;
		delete ref_count;
	}
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> & other)
{
	if(this!=&other)
	{
		if(--(*ref_count)==0)
		{
			delete[] data;
			delete ref_count;
		}
		rows = other.rows;
		cols = other.cols;
		data = other.data;
		ref_count = other.ref_count;
		++(*ref_count);
	}
	cout<<"assign, ref_count = "<<(*ref_count)<<endl;
	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
{
	
	Matrix<T> res{cols,rows};
	for(size_t i=0;i<cols*rows;i++)
	{
		res.data[i] = data[i]+other.data[i];
	}
	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const
{
	
	Matrix res{cols,rows};
	for(size_t i=0;i<cols*rows;i++)
	{
		res.data[i] = data[i]-other.data[i];
	}
	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const
{
	
	Matrix res{cols,other.rows};
	for(size_t i=0;i<cols*other.rows;i++)
	{
		float tmp = 0;
		size_t col = i/cols;
		size_t row = i%other.rows;
		for(size_t j=0;j<rows;j++)
		{
			tmp+=data[col*cols+j]*other.data[cols*j+row];
		}
		res.data[i] = tmp;
	}
	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator+=(const Matrix<T>& other)
{
	for(size_t i=0;i<cols*rows;i++)
	{
		data[i] = data[i]+other.data[i];
	}
	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator-=(const Matrix<T>& other)
{
	for(size_t i=0;i<cols*rows;i++)
	{
		data[i] = data[i]-other.data[i];
	}
	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const T& other) const
{
	
	Matrix<T> res{cols,rows};
	for(size_t i=0;i<cols*rows;i++)
	{
		res.data[i] = data[i]+other;
	}
	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const T& other) const
{
	
	Matrix<T> res{cols,rows};
	for(size_t i=0;i<cols*rows;i++)
	{
		res.data[i] = data[i]-other;
	}
	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const T& other) const
{
	
	Matrix<T> res{cols,rows};
	for(size_t i=0;i<cols*rows;i++)
	{
		res.data[i] = data[i]*other;
	}
	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator+=(const T& other)
{
	
	for(size_t i=0;i<cols*rows;i++)
	{
		data[i] = data[i]+other;
	}
	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator-=(const T& other)
{
	
	for(size_t i=0;i<cols*rows;i++)
	{
		data[i] = data[i]-other;
	}
	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator-() const
{
	Matrix<T> res{cols,rows};
	for(size_t i=0;i<cols*rows;i++)
	{
		res.data[i] = -data[i];
	}
	return res;
}

template<class T>
T Matrix<T>::operator()(size_t row,size_t col)
{
	return data[row*rows+col];
}

template<class T>
T& Matrix<T>::operator()(size_t row,size_t col) const
{
	return data[row*rows+col];
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
	for(size_t i=0;i<m.cols*m.rows;i++)
	{
		os<<m.data[i]<<" ";
		if(i%m.rows==m.rows-1)
			os<<endl;
	}
	return os;
}

int main(int argc, char const *argv[])
{
	Matrix<int> a(3,4);
	Matrix<int> b{3,4};
	for(int i=0;i<a.rows*a.cols;i++)
		a.data[i]=i;
	a.print();
	for(int i=0;i<b.rows*b.cols;i++)
		b.data[i]=1-i;
	b.print();
	a+=b;
	a.print();
	a-=b;
	a.print();
	cout<<a(1,2)<<endl;
	return 0;
}