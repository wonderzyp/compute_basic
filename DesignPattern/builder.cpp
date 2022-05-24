#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Product1{
public:
  vector<string> parts_;
  void ListParts() const{
    cout<<"Product parts: ";

  }
};

class Builder{
public:
  virtual ~Builder(){};
  
}