#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <chrono>
#define LOG(x) std::cout<<x<<std::endl

class MTsafe_Singleton
{
private:
  static MTsafe_Singleton* m_instance;
  static std::mutex m_mutex;

protected:
  MTsafe_Singleton(const std::string& _value):m_value(_value){}
  ~MTsafe_Singleton(){}
  std::string m_value;
public:
  MTsafe_Singleton(const MTsafe_Singleton& other) = delete;
  void operator=(const MTsafe_Singleton& ) = delete;

  static MTsafe_Singleton* getInstance(const std::string& value);
  std::string getValue()const{
    return m_value;
  }
};

// 静态需在类外定义
// 类中仅是声明
MTsafe_Singleton* MTsafe_Singleton::m_instance{nullptr};
std::mutex MTsafe_Singleton::m_mutex;

// 进入前先上锁
MTsafe_Singleton* MTsafe_Singleton::getInstance(const std::string& value){
  std::lock_guard<std::mutex> lock(m_mutex);
  if (m_instance == nullptr){
    m_instance = new MTsafe_Singleton(value);
  }
  return m_instance;
}

void Thread1(){
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  MTsafe_Singleton* mTsafe_Singleton = MTsafe_Singleton::getInstance("Created a Singleton");
  LOG(mTsafe_Singleton->getValue());
}

void Thread2(){
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  MTsafe_Singleton* mTsafe_Singleton = MTsafe_Singleton::getInstance("Again!!! Created a Singleton");
  LOG(mTsafe_Singleton->getValue());
}


int main(){
  LOG("Outputs should be same");
  std::thread t1(Thread1);
  std::thread t2(Thread2);
  t1.join();
  t2.join();
  return 0;
}