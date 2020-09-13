#ifndef LISTSTACK_H_
#define LISTSTACK_H_
#include <iostream>

using namespace std;
template <class T>
class ListStack {
private:
    struct StackNode;
    struct StackNode {
        T data;
        StackNode* next;
        StackNode():next(nullptr){}
        StackNode(T val):data(val), next(nullptr) {}
    };
public:
    enum Status {Error, OK, Warning};
    ListStack():top(nullptr), length(0){}
    ~ListStack();
    ListStack(const ListStack<T>& lstack);
    
    Status push(T val);
    T pop();
    T getTop() const {return top->data;}
    int size() const {return length;}
    int isEmpty() const {return top == nullptr;}
    ListStack<T>& operator=(const ListStack<T>& lstack);
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const ListStack<U>& lstack);
private:
    StackNode* top;
    int length;
};

template <class T>
ListStack<T>::ListStack(const ListStack<T>& lstack) {
    StackNode* p = lstack.top;
    StackNode* temp = nullptr;
    StackNode* newNode = nullptr;
    length = 0;
    while(p != nullptr) {
        if(length == 0) {
            top = new StackNode(p->data);
            temp = top;
            length++;
        } else {
            newNode = new StackNode(p->data);
            temp->next = newNode;
            temp = newNode;
            length++;
        }
        p = p->next;
    }
}

template<class T>    
typename ListStack<T>::Status ListStack<T>::push(T val){
    Status st = OK;
    StackNode* newNode = new StackNode(val);
    newNode->next = top;
    top = newNode;
    length++;
    return st;
}

template <class T>
T ListStack<T>::pop() {
    int val = 0;
    if (top != nullptr) {
        StackNode* p = top;
        top = p->next;
        val = p->data;
        delete p;
        p = nullptr;
        length--;
    } else{
        cout << "empty stack no element to be poped" << endl;
    }
    return val;    
}
template <class T>
ListStack<T>& ListStack<T>::operator=(const ListStack<T>& lstack) {
    StackNode* p = lstack.top;
    StackNode* temp = nullptr;
    StackNode* newNode = nullptr;
    while(p != nullptr) {
        if(length == 0) {
            top = new StackNode(p->data);
            temp = top;
            length++;
        } else {
            newNode = new StackNode(p->data);
            temp->next = newNode;
            temp = newNode;
            length++;
        }
        p = p->next;
    }
    return *this;
}
template <class U>
std::ostream& operator<<(std::ostream& os, const ListStack<U>& lstack) {
    typename ListStack<U>::StackNode* p = lstack.top;
    while (p != nullptr) {
        os <<p->data <<" ";
        p = p->next;
    }
    return os;
}
template <class T>
ListStack<T>::~ListStack(){
    while(length != 0) {
        pop();
    }
}
#endif  