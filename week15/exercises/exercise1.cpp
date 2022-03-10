#include <iostream>
using namespace::std;
int clip(int value,int min,int max)
{
	if(value<min)
	{
		value = min;
	}
	if(value>max)
	{
		value = max;
	}
	return value;
}
class Car
{

private:
	enum{Off,On};
	enum{Minvel,Maxvel=200};
	int mode;
	int velocity;
public:
	Car (int m=On,int v=50):mode(m),velocity(v){}
	bool velup(int v){cout<<"Increase velocity by car!";mode=On; velocity+=v; velocity = clip(velocity, Minvel, Maxvel); return velocity<=Maxvel&&velocity>=Minvel;}
	bool veldown(int v){cout<<"Decrease velocity by car!";mode=On; velocity-=v; velocity = clip(velocity, Minvel, Maxvel);return velocity<=Maxvel&&velocity>=Minvel;}
	bool ison() const{return mode;};
	int getvel() const{return velocity;}
	void showinfo() const{
		string smode[2] = {"Off","On"};
		cout<<"The information of car: mode is "<<smode[mode]<<", velocity is "<<velocity<<"."<<endl;};
	friend class Driver;
};

class Driver
{

public:
	bool velup(Car& car,int v){cout<<"Increase velocity by driver!";car.mode=Car::Off;car.velocity+=v; car.velocity = clip(car.velocity, car.Minvel, car.Maxvel); return car.velocity<=car.Maxvel&&car.velocity>=car.Minvel;}
	bool veldown(Car& car,int v){cout<<"Decrease velocity by driver!";car.mode=Car::Off;car.velocity-=v; car.velocity = clip(car.velocity, car.Minvel, car.Maxvel); return car.velocity<=car.Maxvel&&car.velocity>=car.Minvel;}
	void setmode(Car& car){car.mode=(ison(car)?0:1);};
	bool ison(Car& car) const{return car.ison();}
};
int main()
{
	Car car;
	Driver driver;
	car.showinfo();
	car.velup(100);
	car.showinfo();
	driver.velup(car, 100);
	car.showinfo();
	driver.veldown(car, 100);
	car.showinfo();
	car.veldown(200);
	car.showinfo();
}