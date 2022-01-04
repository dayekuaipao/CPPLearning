#include <climits>
#include <iostream>
using namespace std;
int main()
{
    int min = INT_MIN, max = INT_MAX;
    int min_ = min - 1;
    int max_ = max + 1;
    cout << "min: " << min << "max: " << max << endl;
    cout << "min - 1 = " << min_ << ", max + 1 = " << max_ << endl;
}