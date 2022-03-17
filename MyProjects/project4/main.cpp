#include "matrix.h"
int main(int argc, char const *argv[])
{
	Mat a(3,4,1.1);
	Mat b(3,4,2.2);
	Mat c(4,5,5.5);

	a+=b;
	a.print();
	a-=b;
	a.print();
	a*=b;
	a.print();
	a=a.matmul(c);
	a.print();
	a=b;
	a.print();
	b-=1;
	b.print();
	Mat d = c.roi(1,1,4,3);
	a+=d;
	a.print();
	d.copyFrom(a);
	c.print();
	b.copyTo(d);
	c.print();
	Mat e = d.roi(0,1,2,2);
	e.copyFrom(a.roi(1,0,2,2));
	e.print();
	c.print();
	std::cout<<(a.roi(1,0,2,2)==e)<<std::endl;
	std::cout<<(a==b)<<std::endl;
	return 0;
}