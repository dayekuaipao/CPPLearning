#include<iostream>
using namespace std;
int main()
{
    char str[20];
    cout<<"Enter a string:"<<endl;
    cin.get(str,20);
    cout<<"You entered:"<<str<<endl;

    cin.get();
    cout<<"Enter another string:"<<endl;
    cin.get(str,20);
    cout<<"You entered:"<<str<<endl;
    return 0;
}