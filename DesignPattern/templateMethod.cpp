#include <iostream>
#include <string>
using namespace std;

// 抽象基类定义一系列的算法框架
// 实现子类需实现这些操作, but leave the temp method itself intact
// Hook是内容为空的可选步骤，即使不重写也可工作，为子类提供额外的扩展点
class AbstractClass{
public:
void TemplateMethod() const{
  this->Func();
  this->VirtualFunc();
  this->Hook();
}

protected:
  void Func() const{
    cout<<"AbstractClass doing sth"<<endl;
  }

  virtual void VirtualFunc() const = 0;

  virtual void Hook() const {};
};

class ConcreteClass1 : public AbstractClass{
protected:
  void VirtualFunc() const override {
    cout<<"ConcreteClass1 virtual func"<<endl;
  }
};

class ConcreteClass2 : public AbstractClass{
protected:
  void VirtualFunc() const override{
    cout<<"ConcreteClass1 virtual func"<<endl;
  }

  void Hook() const override {
    cout<<"ConcreteClass2 hook"<<endl;
  }
};

void ClientCode(AbstractClass* abClass){
  abClass->TemplateMethod();
}


int main(){
  ConcreteClass1* c1 =  new ConcreteClass1;
  ClientCode(c1);

  cout<<"-------------------"<<endl;

  ConcreteClass2* c2 = new ConcreteClass2;
  ClientCode(c2);
}