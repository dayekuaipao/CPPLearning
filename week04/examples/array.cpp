#include <iostream>
using namespace std;
int main()
{
    int num_array1[5]; //uninitialized array, random values 
    int num_array2[5] = {0, 1, 2, 3, 4}; //initialization
    int num_array3[5]={2,2};
    int num_array4[5]{1}; 

    for(int idx = 0; idx < 5; idx++)
        cout << num_array1[idx] << " ";
    cout << endl;

    for(int idx = 0; idx < 5; idx++)
        cout << num_array2[idx] << " ";
    cout << endl;

    for(int idx = 0; idx < 5; idx++)
        cout << num_array3[idx] << " ";
    cout << endl;

    for(int idx = 0; idx < 5; idx++)
        cout << num_array4[idx] << " ";
    cout << endl;

    return 0;
}
