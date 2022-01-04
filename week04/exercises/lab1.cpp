#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int arr[10];
    arr[0] = 0;
    arr[1] = 1;

    // print the first element in arr
    cout<<arr[0]<<endl;

    // this is wrong:
    cout<<arr[10]<<endl;

return 0;
}
