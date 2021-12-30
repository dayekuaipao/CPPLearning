#include <float.h>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    float a = 0.1;
    float sum = a + a + a + a + a + a + a + a + a + a;
    float sum2 = 10 * a;
    cout << std::fixed << "sum: " << sum << endl;
    cout << "sum equals to 1? " << (sum == 1.0) << endl;
    cout << "sum2 equals to 1? " << (sum2 == 1.0) << endl;
    cout << "sum is close to 1?" << (abs(sum - 1.0) < FLT_EPSILON) << endl;

    return 0;
}