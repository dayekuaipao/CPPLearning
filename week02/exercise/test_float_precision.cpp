#include <iostream>
#include <iomanip>
using namespace std;
void printFloat(float num)
{
    int inum = *(int *)&num;
    for (int i = 0; i < 32; ++i)
    {
        cout << ((inum & 0x80000000) ? 1 : 0);
        if (i == 0 || i == 8)
            cout << " ";
        inum <<= 1;
    }
    cout << endl;
}

int main()
{
    float f1 = 1.0;
    cout << std::fixed <<std::setprecision(16)<< "f1 = " << f1 << endl;
    cout << "The binary presentaion of f1"
         << " is:" << endl;
    printFloat(f1);
    cout << endl;

    float a = 0.1;
    float f2 = a + a + a + a + a + a + a + a + a + a;
    cout << std::fixed <<std::setprecision(16)<< "f2 = " << f2 << endl;
    cout << "The binary presentaion of f2"
         << " is:" << endl;
    printFloat(f2);
    cout << endl;

    float f3 = 4.0;
    cout << std::fixed <<std::setprecision(16)<< "f3 = " << f3 << endl;
    cout << "The binary presentaion of f3"
         << " is:" << endl;
    printFloat(f3);
    cout << endl;

    return 0;
}