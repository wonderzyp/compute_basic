#include <iostream>
#include <string>

#define LOG(x) std::cout<<x<<std::endl
using namespace std;

//设想生产两种家具：桌子 椅子
//每种家具有两种型号：大 小
// 大桌子可且仅可配合大椅子使用
// 小桌子和小椅子
class AbstractChair{
public:
  virtual ~AbstractChair(){};
  virtual std::string chairSize() const = 0; 
};

class BigChair : public AbstractChair{
public:
  std::string chairSize() const override{
    return "big chair";
  }
};

class SmallChair : public AbstractChair{
public:
  std::string chairSize() const override{
    return "small chair";
  }
};

class AbstractTable{
public:
  virtual ~AbstractTable(){};
  virtual std::string tableSize() const = 0;
  virtual std::string workWithChair(const AbstractChair& collaborator) const = 0;
};

class BigTable : public AbstractTable{
public:
  std::string tableSize() const {
    return "Big table";
  }

  std::string workWithChair(const AbstractChair& collaborator) const override{
    const std::string result = collaborator.chairSize();
    return "Big table with "+ result;
  }
};

class SmallTable : public AbstractTable{
public:
  std::string tableSize() const {
    return "Small Table";
  }

  std::string workWithChair(const AbstractChair& collaborator) const override{
    const std::string result = collaborator.chairSize();
    return "Small table with "+result;
  }
};


// 抽象工厂代码
class AbstractFactory{
public:
  virtual AbstractChair *createChair() const = 0;
  virtual AbstractTable *createTable() const = 0;
};

class BigFactory : public AbstractFactory {
public:
  AbstractChair *createChair() const override{
    return new BigChair();
  }
  
  AbstractTable *createTable() const override{
    return new BigTable();
  }
};


class SmallFactory : public AbstractFactory{
public:
  AbstractChair *createChair() const override{
    return new SmallChair();
  }

  AbstractTable *createTable() const override{
    return new SmallTable();
  }
};

void ClientCode(const AbstractFactory& factory){
  const AbstractChair *chair = factory.createChair();
  const AbstractTable *table = factory.createTable();
  cout<<table->tableSize()<<endl;
  cout<<table->workWithChair(*chair)<<endl;
  delete chair;
  delete table;
}

int main(){
  BigFactory *bigFactory = new BigFactory();
  ClientCode(*bigFactory);
  delete bigFactory;
}
