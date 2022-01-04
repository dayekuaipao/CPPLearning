#include<iostream>
using namespace std;
float array_sum1(float values[],int length)
{
    float sum = 0.f;
    for(int i=0;i<length;i++)
    {
        sum+=values[i];
    }
    return sum;
}

float array_sum2(float* values,int length)
{
    float sum = 0.f;
    for(int i=0;i<length;i++)
    {
        sum+=values[i];
    }
    return sum;
}

float array_sum3(float values[5])// just like: float array_sum(float values[]),5 makes no sense.
{
    float sum = 0.f;
    for(int i=0;i<5;i++)
    {
        sum+=values[i];
    }
    return sum;
}
int main()
{
    float values[3] = {1,2,3};
    cout<<"array sum1:"<<array_sum1(values,sizeof(values)/sizeof(float))<<endl;
    cout<<"array sum2:"<<array_sum2(values,sizeof(values)/sizeof(float))<<endl;
    cout<<"array sum3:"<<array_sum3(values)<<endl;
}

