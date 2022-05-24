// 二叉堆实现优先级队列
// 插入、删除元素的时间复杂度为logN

#include <iostream>
#include <vector>
using namespace std;

namespace myALGO{

template<typename T>
class BinaryHead{
public:
  // 索引0搁置，因此多分配一个空间
  BinaryHead(int _cap): capacity(_cap){
    cache.resize(capacity+1);
  }

  T max(){
    return cache[1];
  }

  // 先将新元素加至最后，再上浮
  void insert(T val){
    ++N;
    cache[N] = e;
    swim(N);
  }

  // 先将栈顶元素与栈底对调，再删除对调后的栈底元素
  // 最后将栈顶元素下沉
  T deleteMax(){
    T maxVal = pq[1];
    exch(1,N);
    pq[N] = nullptr;
    --N;
    sink(1);
    return maxVal;
  }

private:
  
  // 结点大于其父节点，上浮
  void swim(int k){
    while(k>1 && lessThan(parent(k), k)){
      exch(parent(k),k);
      k = parent(k);
    }
  }

  // 结点小于子节点之一
  void sink(int k){
    while(left(k)<=N){
      int older = left(k);
      if (right(k) <= N && lessThan(older, right(k)))
        older = right(k);
      if (lessThan(older, k)) break;
      exch(k, older);
      k = older;
    }
  }

  void exch(int i, int j){
    T temp = cache[i];
    cache[i] = cache[j];
    cache[j] = temp;
  }

  bool lessThan(int i, int j){
    return cache[i]<cache[j];
  }

// 数组内寻找父子结点的索引映射关系
private:
  int parent(int root){
    return root/2;
  }

  int left(int root){
    return root*2;
  }

  int right(int root){
    return root*2+1;
  }

private:
  vector<T> cache;   // 存储元素的数组
  size_t N = 0;        // 当前数组内的元素个数
  size_t capacity;

};

}// namespace myALGO

