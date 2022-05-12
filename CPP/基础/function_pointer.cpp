#include <iostream>
#include <vector>
using namespace std;
#define LOG(x) cout<<x<<endl

void func1(){
  LOG("Hello");
}

int func2(char c){
  LOG(c);
  return 1;
}

void printValue(int value){
  cout<<"Value: "<<value<<endl;
}

void ForEach(const vector<int>& vec, void(*func)(int)){
  for(int value : vec){
    func(value);
  }
}


int main(){
  // 函数指针基础
  {
    // 无参函数
    // void (*fptr_1)()
    auto fptr_1 = func1;
    fptr_1();

    auto fptr_2 = func2;
    cout<<fptr_2('a')<<endl;

    // 显式样子
    int (*fptr_3)(char) = func2;
    fptr_3('p');

    // 借助typedef
    typedef int(*fptr_2_type)(char);
    fptr_2_type temp = func2;
    temp('S');
  }
  LOG("----------Function Pointer In Paras----------");
  // 函数指针实战
  {
    vector<int> nums{1,8,3,4,9};
    ForEach(nums, printValue);

    auto EachElemAddone = [](int a){cout<<"Using lambda: "<<a+1<<endl;};
    ForEach(nums, EachElemAddone);
  }
}


