#include <iostream>

using namespace std;

// 原始版本
#if 0
class Test{
public:
  Test(const string& t) : m_text(t){};

  const char& operator[] (std::size_t i) const{
    cout<<"const operator"<<endl;
    return m_text[i];
  }

  char& operator[] (std::size_t i){
    cout<<"normal operator"<<endl;
    return m_text[i];
  }

private:
  string m_text;
};
#endif

// 代码复用版本
// non-const复用const
class Test{
public:
  Test(const string& t) : m_text(t){};

  const char& operator[] (std::size_t i) const{
    cout<<"const operator"<<endl;
    return m_text[i];
  }

  char& operator[] (std::size_t i){
    cout<<"normal operator"<<endl;

    return const_cast<char&>(
      static_cast<const Test&>(*this)[i]
    );

  }

private:
  string m_text;
};


int main(){
  const Test test_const("Hello");
  cout<<test_const[2]<<endl;

  Test test_normal("World");
  cout<<test_normal[2]<<endl;
}