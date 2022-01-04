#include "mul.hpp"
#include <iostream>

using namespace std;
int main()
{
    int a, b;
    int result;

    cout << "Pick two integers:";
    cin >> a;
    cin >> a;

    cout << "a = " << a << ", b = " << b << endl;

    result = mul(a, b);

    cout << "The result is " << result << endl;
    return 0;
}