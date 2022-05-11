#include <iostream>
#define LOG(x) std::cout<<x<<std::endl


class Singleton
{
public:
  Singleton(const Singleton&) = delete;  // 不允许拷贝
  void operator=(const Singleton&) = delete;
  
  static Singleton& GetInstance(){
    return m_Instance;
  }
  static void Func(){
    Singleton::GetInstance().Ifun();
  }

private:
  Singleton(){  //私有化构造函数，避免对外实例化
    ++m_Member;
    LOG("You have created a singleton");
  }; 

  void Ifun(){
    LOG(m_Member);
  }
  static Singleton m_Instance;
  float m_Member = 0.0f;
};

Singleton Singleton::m_Instance;


int main(){
  // Singleton::Ifun();  非静态成员函数必须与一个实现类相关联

  // 使用麻烦，考虑将Ifun成员函数打包
  // Singleton::GetInstance().Ifun();
  // Singleton::GetInstance().Ifun();
  // Singleton::GetInstance().Ifun();
  // Singleton::GetInstance().Ifun();

  Singleton::Func();
  Singleton::Func();
  Singleton::Func();
  Singleton::Func();
  Singleton::Func();
}

