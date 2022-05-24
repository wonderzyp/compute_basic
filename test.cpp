#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

template <class T>
class NameObject{
public:
  NameObject(string& name, const T& value) : nameValue(name), price(value){};


 // string& nameValue;
  const T price;
};


int main(){
  string newBook{"newBook"};
  string oldBook{"oldBook"};

  NameObject<int> newbook(newBook, 10);
  NameObject<int> oldbook(oldBook, 1);

  cout<<newbook.price<<endl;

  newbook = oldbook;

  cout<<newbook.price<<endl;
}