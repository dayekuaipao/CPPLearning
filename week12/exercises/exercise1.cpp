#include <algorithm>
#include<iostream>
#define PI 3.14f
using namespace std;
class CStereoShape
{
public:
	virtual float GetArea(){cout<<"CStereoShape::GetArea()"<<endl;return 0.f;}
	virtual float GetVolume(){cout<<"CStereoShape::GetVolume()"<<endl;return 0.f;}
	virtual void Show(){cout<<"CStereoShape::Show()"<<endl;}
	int getNumOfObject(){return numberOfObject;}
	CStereoShape(){numberOfObject++;}
	CStereoShape(const CStereoShape& other){numberOfObject++;}
	virtual ~CStereoShape(){numberOfObject--;cout<<"Number of object is "<<numberOfObject<<endl;}
private:
	static int numberOfObject;
};
int CStereoShape::numberOfObject=0;
class CCube:public CStereoShape
{
public:
	CCube():CStereoShape(){}
	CCube(float length,float width,float height):length(length),width(width),height(height),CStereoShape(){};
	CCube(const CCube& other):length(other.length),width(other.height),height(other.height),CStereoShape(other){}
	float GetArea(){return 2*(width*height+width*length+length*height);}
	float GetVolume(){return height*length*width;}
	void Show(){cout<<"The cube`s height = "<<height<<", width = "<<width<<", length = "<<length<<", area = "<<GetArea()<<", volume = "<<GetVolume()<<endl;}
private:
	float length;
	float width;
	float height;
};
class CSphere:public CStereoShape
{
public:
	CSphere():CStereoShape(){}
	CSphere(float radius):radius(radius),CStereoShape(){};
	CSphere(const CSphere& other):radius(other.radius),CStereoShape(other){}
	float GetArea(){return 4*PI*radius*radius;}
	float GetVolume(){return PI*radius*radius*radius*4/3;}
	void Show(){cout<<"The sphere`s radius = "<<radius<<", area = "<<GetArea()<<", volume = "<<GetVolume()<<endl;}
private:
	float radius;
};
int main()
{
	CCube a_cube(4.0,5.0,6.0);
	CSphere c_sphere(7.9);
	CStereoShape* p = &a_cube;
	p->Show();
	p=&c_sphere;
	p->Show();
	cout<<p->getNumOfObject()<<" objects are created."<<endl;
}