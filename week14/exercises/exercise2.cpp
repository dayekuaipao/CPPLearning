#include <cstdio>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
float calculateAverage(vector<int> v)
{
	float avg=0;
	for(int i=0;i<v.size();i++)
	{
		assert(v[i]>=0&&v[i]<=100);
		avg+=v[i]*1.0/v.size();
	}
	return avg;
}
int main(int argc, char const *argv[])
{
	bool flag = true;
	do
	{
		vector<int> v;
		cout<<"Please enter marks for 4 courses:";
		int a[4];;
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		for(int i=0;i<4;i++)
		{
			v.push_back(a[i]);
		}
		
		float res = calculateAverage(v);
		cout<<"The average of the four courses is "<<res<<endl;
		cout<<"Would you want to enter another marks for 4 courses(y/n)?";
		char an;
		cin>>an;
		if(an!='y')
		{
			flag=false;
			cout<<"Bye, see you next time."<<endl;
		}
	}
	while(flag);
	return 0;
}