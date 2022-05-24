#include <iostream>

using namespace std;

//1. 类中有虚函数，则需虚析构函数
#if 0
class Base{
public:
  Base(){};
  virtual void func(){cout<<"base"<<endl;}
  // 若非虚函数，则无法调用派生类的析构函数
  virtual ~Base(){ cout<<"deconstruct base"<<endl; };
};

class Derived : public Base{
public:
  Derived(){};
  void func() override {cout<<"deriver"<<endl;}
  ~Derived(){cout<<"deconstruct derived"<<endl;}
};

int main(){
  {
    Derived d;
    d.func();
  }

  cout<<"------------------------"<<endl;

  {
    // 若base类的析构非虚函数，则无法调用派生类的析构
    Base* bPtr = new Derived();
    bPtr->func();
    delete bPtr;
  }
}
#endif

// 不使用虚析构函数，则无法调用派生类的析构函数
// 可能导致内存泄漏
#if 0
class Base{
public:
  Base(){};
  virtual void func(){cout<<"base"<<endl;}
  // 若非虚函数，则无法调用派生类的析构函数
  ~Base(){ cout<<"deconstruct base"<<endl; };
};

class Derived : public Base{
public:
  Derived(){
    a = new int(10);
  };
  void func() override {cout<<"deriver"<<endl;}

  ~Derived(){
    cout<<"deconstruct derived"<<endl;
    delete a;
    }
private:
  int* a;
};

int main(){
  Base* bPtr = new Derived();
  delete bPtr;
}
#endif