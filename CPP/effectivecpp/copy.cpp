#include <iostream>

using namespace std;


// 派生类的拷贝构造函数未处理基类成员
// 因此基类成员的值不会被拷贝，而是调用基类的默认构造函数产生
class Base{
public:
  int a = 10;
};

class Derived : public Base{
public:
  int b;
  Derived():b(11){};
  Derived(const Derived&);
};

Derived::Derived(const Derived& rhs) : b(rhs.b){
  cout<<"Derived Copy Constructor"<<endl;
}


int main(){
  Derived d1;
  d1.a = 100;
  Derived d2(d1);
  cout<<d2.a<<endl;
}
