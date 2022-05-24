并发编程相关
---


基础知识
---
#### 函数指针
函数存储在计算机内部，自然是有一个地址的；
函数指针指向一个存储函数的地址，形式上较奇怪：
`void func()`的函数指针为：`void(*fptr)()`
`int fun(char)`的函数指针为：`int(*fptr1)(char)`
使用时调用括号即可: `return fptr1('a');`

此外，可使用`typedef`简化代码
```cpp
typedef int(*fptr1)(char);
fptr1 temp = fun;
temp('a');
```

函数指针作为参数，可传入符合函数指针参数与返回值的一切函数或lambda表达式；
其内部功能可自定义

Effective C++
---

#### 常量性质
1. 使用`inline template function`代替宏函数
2. `static_cast`搭配`const_cast`实现代码复用





