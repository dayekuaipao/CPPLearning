#include "iostream"
using namespace std;
int main()
{
    char c = '&';
    int a = (int)c;
    cout << "a = " << a << endl;
    a = 124;
    c = (char)a;
    cout << "c = " << c << endl;
}