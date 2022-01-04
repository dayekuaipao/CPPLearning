#include <iostream>
using namespace std;

struct Rectangle {
    int width;
    int height;
};

int main() {
    Rectangle rec;

    rec.width = 1;
    rec.height = 2;

    cout<<rec.width<<" "<<rec.height<<endl;

    Rectangle rec2 = rec;
    rec2.width = 3;
    cout<<rec.width<<" "<<rec.height<<endl;
    cout<<rec2.width<<" "<<rec2.height<<endl;

return 0;
}
