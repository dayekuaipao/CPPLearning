#include <iostream>
#include <ostream>
using namespace::std;
class Matrix{
public:
	size_t cols;
	size_t rows;
	float * data;
	Matrix(size_t cols,size_t rows);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator=(const Matrix& other);
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	Matrix operator+(const float& other) const;
	Matrix operator-(const float& other) const;
	Matrix operator*(const float& other) const;
	Matrix operator-() const;
	friend Matrix operator+(const float& a,const Matrix& b);
	friend Matrix operator-(const float& a,const Matrix& b);
	friend Matrix operator*(const float& a,const Matrix& b);
	friend ostream& operator<<(ostream& os,const Matrix& m);
private:
	size_t* ref_count;
};

Matrix::Matrix(size_t cols,size_t rows):cols(cols),rows(rows)
{
	data = new float[cols*rows];
	ref_count = new size_t(1);
	cout<<"constrctor, ref_count = "<<(*ref_count)<<endl;
}

Matrix::Matrix(const Matrix& other):cols(other.cols),rows(other.rows),data(other.data),ref_count(other.ref_count)
{
	++(*ref_count);
	cout<<"copy constrctor, ref_count = "<<(*ref_count)<<endl;
}

Matrix::~Matrix()
{
	cout<<"destrctor, ref_count = "<<(*ref_count)<<endl;
	if(--(*ref_count)==0)
	{
		delete[] data;
		delete ref_count;
	}
}

Matrix& Matrix::operator=(const Matrix & other)
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
Matrix Matrix::operator+(const Matrix& other) const
{
	
	Matrix res{cols,rows};
	for(size_t i=0;i<cols*rows;i++)
	{
		res.data[i] = data[i]+other.data[i];
	}
	return res;
}
Matrix Matrix::operator-(const Matrix& other) const
{
	
	Matrix res{cols,rows};
	for(size_t i=0;i<cols*rows;i++)
	{
		res.data[i] = data[i]-other.data[i];
	}
	return res;
}
Matrix Matrix::operator*(const Matrix& other) const
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
Matrix Matrix::operator+(const float& other) const
{
	
	Matrix res{cols,rows};
	for(size_t i=0;i<cols*rows;i++)
	{
		res.data[i] = data[i]+other;
	}
	return res;
}
Matrix Matrix::operator-(const float& other) const
{
	
	Matrix res{cols,rows};
	for(size_t i=0;i<cols*rows;i++)
	{
		res.data[i] = data[i]-other;
	}
	return res;
}
Matrix Matrix::operator-() const
{
	Matrix res{cols,rows};
	for(size_t i=0;i<cols*rows;i++)
	{
		res.data[i] = -data[i];
	}
	return res;
}
Matrix Matrix::operator*(const float& other) const
{
	
	Matrix res{cols,rows};
	for(size_t i=0;i<cols*rows;i++)
	{
		res.data[i] = data[i]*other;
	}
	return res;
}
Matrix operator+(const float& a,const Matrix& b)
{
	return b+a;
}
Matrix operator-(const float& a,const Matrix& b)
{
	return -b+a;
}
Matrix operator*(const float& a,const Matrix& b)
{
	return b*a;
}
ostream& operator<<(ostream& os,const Matrix& m)
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
	Matrix a(3,4);
	Matrix b{3,4};
	for(int i=0;i<a.rows*a.cols;i++)
		a.data[i]=i;
	cout<<a;
	for(int i=0;i<b.rows*b.cols;i++)
		b.data[i]=12-i;
	cout<<b;
	Matrix c = a+b;
	cout<<c;
	Matrix d = 2.f*a;
	cout<<d;
	Matrix e{4,3};
	for(int i=0;i<e.rows*e.cols;i++)
		e.data[i]=12-i;
	cout<<e;
	Matrix f = a*e;
	cout<<f;
	Matrix g = f;
	cout<<g;
	g=g;
	cout<<g;
	Matrix h(g);
	cout<<h;
	Matrix i = g+h;
	cout<<i;
	for(int i=0;i<f.rows*f.cols;i++)
		f.data[i]-=1;
	cout<<f;
	cout<<g;
	cout<<h;
	f=f+1;
	cout<<f;
	cout<<g;
	cout<<h;
	return 0;
}