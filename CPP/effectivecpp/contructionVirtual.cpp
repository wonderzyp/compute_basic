#include <iostream>

using namespace std;


// 不可在构造或析构函数中调用虚函数
class Base{
public:
  Base();
  virtual void Log(){cout<<"base"<<endl;}

  virtual ~Base(){cout<<"base deconstruct"<<endl;}
};

Base::Base(){
  Log();
}

class Derived : public Base{
public:
  void Log(){cout<<"derived"<<endl;}
  virtual ~Derived(){cout<<"derived deconstruct"<<endl;}
};

int main(){
  Derived d;
}