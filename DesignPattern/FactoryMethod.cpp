#include <iostream>
#include <string>

#define LOG(x) std::cout<<x<<std::endl

class AbstractHuman{
public:
  virtual void setColor() = 0;
  virtual void getColor() = 0;
  virtual ~AbstractHuman(){};
protected:
  std::string m_color="404 NOT FUNOD";
};

class YellowHuman : public AbstractHuman{
public:
  void setColor() override {
    LOG("Set Color To Yellow");
    m_color = "Yellow";
  }

  void getColor() override {
    LOG("getColor: " + m_color);
  }
};

class BlackHuman : public AbstractHuman{
public:
  void setColor() override {
    LOG("Set Color To Black");
    m_color = "Black";
  }

  void getColor() override {
    LOG("getColor: " + m_color);
  }
};

class WhiteHuman : public AbstractHuman{
public:
  void setColor() override {
    LOG("Set Color To White");
    m_color = "White";
  }

  void getColor() override {
    LOG("getColor: " + m_color);
  }
};

// 工厂类声明创建方法，返回一个产品对象
// 工厂类的子类实现对应方法
class AbstractFactory{
public:
  virtual ~AbstractFactory(){};
  virtual AbstractHuman* FactoryMethod() const = 0;

  void DIYfunc() const{
    AbstractHuman* human = this->FactoryMethod();

    human->setColor();
    human->getColor(); 

    delete human;
  }
};

class YelloFactory : public AbstractFactory{
public:
  AbstractHuman* FactoryMethod() const override{
    return (new YellowHuman());
  }
};

class WhiteFactory : public AbstractFactory{
public:
  AbstractHuman* FactoryMethod() const override{
    return (new WhiteHuman());
  }
};

class BlackFactory : public AbstractFactory{
public:
  AbstractHuman* FactoryMethod() const override{
    return (new BlackHuman());
  }
};

void showYourself(const AbstractFactory& factory){
  LOG("Client: Not aware of the product's class, but it still works");
  factory.DIYfunc();
}

int main(){
  LOG("YellowHuman-----------------");
  AbstractFactory* yellowFactory = new YelloFactory();
  showYourself(*yellowFactory);

  LOG("WhiteHuman-----------------");
  AbstractFactory* whiteFactory = new WhiteFactory();
  showYourself(*whiteFactory);

  LOG("BlackHuman-----------------");
  AbstractFactory* blackFactory = new BlackFactory();
  showYourself(*blackFactory);
  // YellowHuman zyp;
  // zyp.setColor();
  // zyp.getColor();

  // BlackHuman litterBlack;
  // litterBlack.setColor();
  // litterBlack.getColor();

  // WhiteHuman litterWhite;
  // litterWhite.setColor();
  // litterWhite.getColor();
}