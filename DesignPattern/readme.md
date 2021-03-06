创建型模式
===
单例模式
---
#### 定义
1. 当创建一个对象的一段时间后，决定再次创建一个新对象，此时仅会获得之前已创建的对象。
2. 为实例提供**全局访问节点**：全局变量可能会被覆盖

#### 实现
有且仅有一个实例类，借助`static`关键字实现
`static`使对应变量“脱离”类，类更近似于一个命名空间
需将拷贝构造函数、拷贝赋值标记为`delete`

> Static methods should be defined outside the class

### 线程安全的单例模式
声明互斥量保护成员变量，构造时先`lock_guard`上锁

> 违反**单一职责原则**，同时解决两个问题？？？


工厂方法模式
---
### 定义
父类提供创建对象的方法，子类决定实例化对象的类型
特点：
1. 工厂与产品之间松耦合
2. 遵循单一职责原则
3. 开闭原则：增加新产品类型不会影响现有类型

生成器模式
---
允许分步骤创建复杂对象，使用相同的创建代码生成不同类型与形式的对象

多用于创建一个可能有多种配置选项的对象时




行为模式
===
模板方法模式
---
抽象基类定义框架，允许子类在不修改结构的前提下重写算法特定步骤
包含必须被子类实现的纯虚函数，以及可选拓展空的虚函数





