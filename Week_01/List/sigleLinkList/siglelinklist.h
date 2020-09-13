#ifndef SINGLELINKLIST_H_
#define SINGLELINKLIST_H_
#include <iostream>
#include <climits>
/*********************模板类********************************************
 * 
 * 1、模板类使用友元函数重载“<<” 运算符：友元的实现不依赖于类，
 *    有两种方法：
 *    1、将友元的实现放于类内部
 *    2、类内声明友元前，为单独配一个模板类型，然后在外部实现。
 * 2、enum类型：类型声明前需要加typename以区分当前名称是类型，而不是变量名称；
 * **********************************************************************/

template<class T>
class SingleList{
private:
    struct ListNode;
    struct ListNode {
        T data;
        ListNode* next;
        ListNode():next(nullptr){}
        ListNode(T val): data(val), next(nullptr){}
    };
    ListNode* head;
    int length;
public:
    enum Status{Error = 0, OK = 1, Warning = 2, OverLength = 3};  
    SingleList();
    SingleList(const SingleList<T> &List);
    ~SingleList();
    Status insert(int i, T val);  
    Status remove(int i, T &val);
    Status insertBefore(T val);
    Status insertPost(T val);
    Status removeFirst(T &val);
    Status removePost(T &val);
    int locateElemt(T val);
    Status getElemt(int i, T& val);
    int listLength() const {return length;}
    T& operator[](int i);
    const T& operator[](int i) const;
    SingleList<T>& operator=(const SingleList<T>& list);
    Status clearList();
    //1、类内实现友元
    friend std::ostream& operator<<(std::ostream& os, SingleList<T>& list) {
        SingleList<T>::ListNode* p = list.head;
        while(p->next) {
            p = p->next;
            os << p->data << " ";
        }
        return os;
    }
    //2、单独声明一个模板，类外实现
    //template <typename U>
    //friend std::ostream& operator<<(std::ostream& os, SingleList<U>& List);

};

//模板类在gcc中不支持，声明与实列分离编译
template<class T>
SingleList<T>::SingleList(){
    head = new ListNode;
    length = 0;
}
template<class T>
SingleList<T>::SingleList(const SingleList<T> &List) {
   head = new ListNode;
   ListNode* r = head;
   ListNode* p = List.head->next;
   ListNode* newNode = nullptr;
   length = List.length;
   while (p)
   {
       
       newNode = new ListNode(p->data);
       newNode->next = r->next;
       r->next = newNode;
       r = newNode;
       
       //insertPost(p->data);
       p = p->next;       
   }
}
template<class T>
typename SingleList<T>::Status SingleList<T>::insert(int i, T val)  {
    ListNode* p = head;
    int j =0 ;
    while (p && j < i-1) {
        p = p->next;
        j++;
    }
    if (!p || j > i-1) return Error;
    ListNode* newNode = new ListNode(val);
    newNode->next = p->next;
    p->next = newNode;
    length++;
    return OK;
}
template<class T>
typename SingleList<T>::Status SingleList<T>::remove(int i, T &val) {
    if(head != nullptr) {
        ListNode* p = head;
        ListNode* q = nullptr;
        int j =0;
        while (p->next && j < i-1)
        {
            p = p->next;
            j++;
        }
        if(!p->next || j > i-1) return Error;
        q = p->next;
        p->next = q->next;
        val = q->data;
        delete q;
        length--;
        return OK;
    }
    return Error;
}
template<class T>
typename SingleList<T>::Status SingleList<T>::insertBefore(T val) {   
    Status st = OK;
    st = insert(1,val);
    return st;
}
template<class T>
typename SingleList<T>::Status SingleList<T>::insertPost(T val) {
    Status st = OK;
    st = insert(length+1,val);
    return st;
}
template<class T>
typename SingleList<T>::Status SingleList<T>::removeFirst(T &val) {
    Status st = OK;
    st = remove(1,val);
    return st;
}
template<class T>
typename SingleList<T>::Status SingleList<T>::removePost(T &val) {
    Status st = OK;
    st = remove(length, val);
    return st;
}
template<class T>
int SingleList<T>::locateElemt(T val) {
    ListNode* p = head->next;
    int j = 1;
    while (p) {
        if (p->data == val) {
            return j;
        }
        p = p->next;
        j++;
    }
    return -1;
}

template<class T>
typename SingleList<T>::Status SingleList<T>::getElemt(int i, T& val) {
    ListNode* p  = head->next;
    int j = 1;
    if (i > length) return Error;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if( !p || j > i) return Error;
    val = p->data;
    return OK;
}

template<class T>
typename SingleList<T>::Status SingleList<T>::clearList() {
    T val;
    while ( length != 0)
    {
        removeFirst(val);
    }
    if (length == 0) {
        head->next = nullptr;
        return OK;
    } else {
        return Error;
    }
}

template<class T>
T& SingleList<T>::operator[](int i) {
    ListNode* p  = head->next;
    i = i + 1;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if( !p || j > i) return head->data;
    return p->data;
}

template<class T>
const T& SingleList<T>::operator[](int i) const {
    ListNode* p  = head->next;
    i = i + 1;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if( !p || j > i) return head->data;
    return p->data;
}

template<class T>
SingleList<T>& SingleList<T>::operator=(const SingleList<T>& List) {
    ListNode* r = head;
    ListNode* p = List.head->next;
    ListNode* newNode = nullptr;
    length = List.length;
    while (p)
    {   
        newNode = new ListNode(p->data);
        newNode->next = r->next;
        r->next = newNode;
        r = newNode;
       
        p = p->next;       
    }
    return *this;
}
/*
template<class U>
std::ostream& operator<<(std::ostream& os, SingleList<U>& list) {
    typename SingleList<U>::ListNode* p = list.head;
    while(p->next) {
        p = p->next;
        os << p->data << " ";
    }
    return os;
}
*/

template<class T>
SingleList<T>::~SingleList() {
    int val;
    clearList();
    if(head->next == nullptr) {
        delete head;
        head = nullptr;
    }
}

#endif
