#include <iostream>
#include <memory>
using namespace std;
class A {
public:
  int a;
  A(int _a) : a(_a){cout<<"Constructor with data: "<<a<<endl;};
  ~A(){cout<<"Destructor with data: "<<a<<endl;};
};
int main(int argc, char const *argv[]) {
  unique_ptr<A> up1(new A(1));
  //unique_ptr<A> up2 = up1;
  unique_ptr<A> up2 = move(up1);
  //A *ptr1 = up1;
  A *ptr1 = up1.get();
  //A *ptr2 = &up1[0];
  A *ptr2 = &up1.get()[0];
}