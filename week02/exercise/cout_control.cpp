#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    cout << 56.8 << setw(12) << 456.77 << endl;
    cout << setprecision(2) << 123.356 << endl;
    cout << setprecision(5) << 3897.678485 << endl;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << 56.8;
    cout.width(12);
    cout.fill('+');
    cout << 456.77 << endl;
    cout.precision(2);
    cout << 123.356 << endl;
    cout.precision(5);
    cout << 3897.678485 << endl;

    cout.unsetf(ios_base::fixed);
    cout << setprecision(2) << 123.356 << endl;
    cout << setprecision(5) << 3897.678485 << endl;
}
