#include <iostream>
using namespace std;

int main()
{
    bool isPositive = true;
    int factor = 0;
    //some operations may change isPositive's value
    if (isPositive)
        factor = 1;
    else
        factor = -1;
    cout << "factor = " << factor << endl;
    //the if-else statement can be replaced by a ternary conditional operation
    factor = isPositive ? 1 : -1;
    cout << "factor = " << factor << endl;

    //sometimes the following code can be more efficient.
    factor = isPositive * 2 - 1;
    cout << "factor = " << factor << endl;

    return 0;
}