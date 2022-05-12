#include <iostream>

using namespace std;

template <typename T> 
inline const T& FindMax(const T& a, const T& b){
  return (a>b)? a : b;
}


int main(){
  int a=2, b=12;
  cout<<FindMax(a,b)<<endl;

  char a1='c', b1='p';
  cout<<FindMax(a1,b1)<<endl;
}