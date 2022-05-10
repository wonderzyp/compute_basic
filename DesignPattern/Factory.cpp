#include <iostream>
#include <string>

#define string std::string
#define LOG(x) std::cout<<x<<std::endl


class AbstractFactory{
public:
};

class Factory : public AbstractFactory{
};



class AbstractHuman{
public:
  virtual void setColor() = 0;
  virtual void getColor() = 0;

protected:
  string m_color="404 NOT FUNOD";
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


void showYourself(AbstractHuman* human){
  human->setColor();
  human->getColor();
}



int main(){

  AbstractHuman* zyp = new YellowHuman();
  showYourself(zyp);


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