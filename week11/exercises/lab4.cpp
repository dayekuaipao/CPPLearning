#include <iostream>
#include <memory>
using namespace std;
class B;
class A {
public:
  unique_ptr<B> pb;
  A(){cout<<"Constructor A"<<endl;}
  ~A(){cout<<"Destructor A"<<endl;}
};
class B {
public:
  unique_ptr<A> pa;
  B(){cout<<"Constructor B"<<endl;}
  ~B(){cout<<"Destructor B"<<endl;}
};
int main()
{
  unique_ptr<A> spa = make_unique<A>();
  unique_ptr<B> spb = make_unique<B>();
  spa->pb = move(spb);
  //spb->pa = move(spa);
}