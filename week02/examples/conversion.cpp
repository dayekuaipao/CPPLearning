#include <iostream>
using namespace std;

int main()
{
    int num_int1 = 9;        // assigning an int value to num_int1
    int num_int2 = 'C';      // implicit conversion
    int num_int3 = (int)'C'; // explicit conversion, C-style
    int num_int4 = int('C'); // explicit conversion, function style
    int num_int5 = 2.8;      //implicit conversion
    float num_float = 2.3;   // implicit conversion from double to float, may loss precision
    short num_short = 650000;

    cout << "num_short = " << num_short << endl;

    int num_int6 = 0x7ABCDEF0;
    float num_int_float = num_int6;
    int num_int7 = (int)(num_int_float);

    cout << std::fixed << "num_int6 = " << num_int6 << ", num_int_float = " << num_int_float
         << ", num_int7 = " << num_int7 << endl;
    return 0;
}
