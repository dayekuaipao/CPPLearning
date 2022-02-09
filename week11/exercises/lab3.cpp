#include <iostream>
#include <memory>
using namespace std;
class B;
class A {
public:
  shared_ptr<B> pb;
  A(){cout<<"Constructor A"<<endl;}
  ~A(){cout<<"Destructor A"<<endl;}
};
class B {
public:
  shared_ptr<A> pa;
  B(){cout<<"Constructor B"<<endl;}
  ~B(){cout<<"Destructor B"<<endl;}
};
int main()
{
  shared_ptr<A> spa = make_shared<A>();
  shared_ptr<B> spb = make_shared<B>();
  spa->pb = spb;
  spb->pa = spa;
}