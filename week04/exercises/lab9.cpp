#include<iostream>
using namespace std;
int main()
{
    string str;
    cout<<"Enter a string:"<<endl;
    getline(cin,str);
    cout<<"You entered:"<<str<<endl;

    cout<<"Enter another string:"<<endl;
    getline(cin,str);
    cout<<"You entered:"<<str<<endl;
    return 0;
}