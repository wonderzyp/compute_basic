#include <iostream>

using namespace std;

// 类的空间布局：内存对齐
#if 0
class Base{
public:
  int a;
  char b;
  Base():a(1),b('b'){};
};

class Derived : public Base{
public:
  int c;
  Derived():c(23){};
};


int main(){
  Base base;
  Derived derived;

  cout<<sizeof(base)<<endl;
  cout<<sizeof(derived)<<endl;

  int a=10;
  cout<<sizeof(a)<<endl;
  char b = 'a';
  cout<<sizeof(b)<<endl;
}
#endif


// 虚函数会导致类的内存增加
#if 0
class Base{
public:
  int a;
  char b;
  Base():a(1),b('b'){};

  void func(){cout<<"base"<<endl;}
  virtual void virtualFunc(){cout<<"base virtual"<<endl;}
};

class Derived : public Base{
public:
  Derived(){};
  void virtualFunc() override {cout<< "derived virtual"<<endl;}

};

int main(){
  
  Base base;
  Derived derived;

  cout<<sizeof(base)<<endl;
  cout<<sizeof(derived)<<endl;

  // int* a = new int(10);
  // cout<<sizeof(a)<<endl;
  // delete(a);
}
#endif

// 空类内存为1
#if 0
class Empty{
};

int main(){
  Empty e;
  cout<<sizeof(e)<<endl;
}
#endif

