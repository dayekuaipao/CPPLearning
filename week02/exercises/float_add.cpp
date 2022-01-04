#include <iostream>

using std::cout;
using std::endl;

int main()
{
    float a = 1234567.0;
    float b = 1.0;
    float sum = a + b;

    cout.setf(std::ios_base::fixed);
    cout << a << " + " << b << " = " << sum << endl;

    return 0;
}