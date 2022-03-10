#include <cstdlib>
#include <exception>
#include <iostream>
using namespace std;
double Quotient1(int a,int b);
double Quotient2(int a,int b);
bool Quotient3(int a,int b,double &d);
double Quotient4(int a,int b);
double Quotient5(int a,int b);
class ZeroDevidedException:public exception
{
	public:
		const char* what()
		{
			return "Divisor can not be zero!";
		}
};

int main(int argc, char const *argv[])
{
	int a,b;
	double d;
	a=5;
	b=0;
	d=Quotient1(a, b);
	cout<<"The Quotient of "<<a<<" and "<<b<<" is "<<d<<endl;
	//d=Quotient2(a, b);
	//cout<<"The Quotient of "<<a<<" and "<<b<<" is "<<d<<endl;
	Quotient3(a, b, d);
	cout<<"The Quotient of "<<a<<" and "<<b<<" is "<<d<<endl;
	try
	{
		d = Quotient4(a, b);
		cout<<"The Quotient of "<<a<<" and "<<b<<" is "<<d<<endl;
	}
	catch(const char* perror)
	{
		cout<<perror<<endl;
	}
	try
	{
		d = Quotient5(a, b);
		cout<<"The Quotient of "<<a<<" and "<<b<<" is "<<d<<endl;
	}
	catch(ZeroDevidedException& ex)
	{
		cout<<ex.what()<<endl;
	}
	return 0;
}

double Quotient1(int a,int b)
{
	return (double)a/b;
}

double Quotient2(int a,int b)
{
	if(b==0)
	{
		cout<<"Divisor can not be zero!"<<endl;
		abort();
	}
	return (double)a/b;
}

bool Quotient3(int a,int b,double &d)
{
	if(b==0)
	{
		return false;
	}
	else
	{
		d = a/b;
		return true;
	}
}

double Quotient4(int a,int b)
{
	if(b==0)
	{
		throw "Divisor can not be zero!";
	}
	return (double)a/b;
}


double Quotient5(int a,int b)
{
	if(b==0)
	{
		throw ZeroDevidedException();
	}
	return (double)a/b;
}