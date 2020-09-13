# 算法训练营第一周学习

## 数据结构

### 1、线性表

1.  顺序表
```cpp
 数据结构：
     typedef struct SequenStack {
       int data*;
       int maxSize;
     };
​ 	SequenStack(int size)	-->初始化大小为size的栈
​	~SequenStack()   		-->销毁栈
​	SequenStack(const SequenStack& lstack)  --> 复制栈
​	push(val) 	--> 压栈
​   pop() 		--> 弹出栈顶元素，并删除栈顶结点
​   getTop() 	--> 获取栈顶元素
​   size() 		--> 获取栈的大小
​	isEmpty()	--> 判定空栈
​	capaticty() --> 当前栈允许的最大空间
​	operator=(const SequenStack& lstack) --> 将已有栈复制给另一个栈   
```
2.  链表
   1. 双向链表
    ```cpp
 	数据结构：
       typedef struct SequenStack {
       int data*;
       int maxSize;
       };
    ```

	 	SequenStack(int size)	-->初始化大小为size的栈
	​	~SequenStack()   		-->销毁栈
	​	SequenStack(const SequenStack& lstack)  --> 复制栈
	​	push(val) 	--> 压栈
	​   pop() 		--> 弹出栈顶元素，并删除栈顶结点
	​   getTop() 	--> 获取栈顶元素
	​   size() 		--> 获取栈的大小
	​	isEmpty()	--> 判定空栈
	​	capaticty() --> 当前栈允许的最大空间
	​	operator=(const SequenStack& lstack) --> 将已有栈复制给另一个栈   
	```
   2. 单链表
   ```cpp
 	数据结构：
     typedef struct SequenStack {
       int data*;
       int maxSize;
     };
	​ 	SequenStack(int size)	-->初始化大小为size的栈
	​	~SequenStack()   		-->销毁栈
	​	SequenStack(const SequenStack& lstack)  --> 复制栈
	​	push(val) 	--> 压栈
	​   pop() 		--> 弹出栈顶元素，并删除栈顶结点
	​   getTop() 	--> 获取栈顶元素
	​   size() 		--> 获取栈的大小
	​	isEmpty()	--> 判定空栈
	​	capaticty() --> 当前栈允许的最大空间
	​	operator=(const SequenStack& lstack) --> 将已有栈复制给另一个栈   
   ```
### 2、栈

1. 顺序栈
```cpp
 数据结构：
     typedef struct SequenStack {
       int data*;
       int maxSize;
     };
​ 	SequenStack(int size)	-->初始化大小为size的栈
​	~SequenStack()   		-->销毁栈
​	SequenStack(const SequenStack& lstack)  --> 复制栈
​	push(val) 	--> 压栈
​   pop() 		--> 弹出栈顶元素，并删除栈顶结点
​   getTop() 	--> 获取栈顶元素
​   size() 		--> 获取栈的大小
​	isEmpty()	--> 判定空栈
​	capaticty() --> 当前栈允许的最大空间
​	operator=(const SequenStack& lstack) --> 将已有栈复制给另一个栈   
```
2. 链栈
```cpp
数据结构：
  	typedef struct StackNode{
    	StackNode* top;
        int length;
        StackNode():top(nullptr),length(0){}
    };
​	ListStack()	     -->初始化栈
​	~ListStack()   	-->销毁栈
​	ListStack(const ListStack& lstack)  --> 复制栈
​	push(val) --> 压栈
​   pop() --> 弹出栈顶元素，并删除栈顶结点
​   getTop() --> 获取栈顶元素
​   size() --> 获取栈的大小
​	isEmpty()--> 判定空栈
​	operator=(const Liststack& lstack) --> 将已有栈复制给另一个栈   
```
3. 测试结果

   ![栈测试结果](C:\Users\huang\Pictures\Saved Pictures\栈测试结果.png)

### 3、队列
	1. 顺序表循环队列
 	2. 链队列
 	3. 双端队列

## 刷题

### 1、两数之和

### 2、移动零

### 3、删除排序数组中的重复元素

### 4、爬楼梯

