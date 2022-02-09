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
  // A a(1);
  // unique_ptr<A> up1(&a);

  A *a = new A(1);
  unique_ptr<A> up1(a);

  cout << up1->a << endl;
  return 0;
}