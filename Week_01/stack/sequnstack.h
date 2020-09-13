#ifndef SEQUENSTACKFILE_H_
#define SEQUENSTACKFILE_H_
#include <iostream>

using namespace std;
template <class T>
class SequenStack{
private:
    T* data;
    int top;
    int stackMax;
public:
    enum Status {Error, OK, Warning};
    SequenStack(int size = 100);
    ~SequenStack();
    SequenStack(const SequenStack<T>& sstack);
    Status push(T val);
    T pop();
    T getTop() const {return data[top];}
    int size() const {return top+1;}
    int capaticty()const{return stackMax;}
    int isEmpty() const {return top == -1;}
    template <class U> 
    friend ostream& operator<<(ostream& os, const SequenStack<U>& sstack);
};

template <class T>
SequenStack<T>::SequenStack(int size):stackMax(size),top(-1) {
    data =  new T [size];
}

template <class T>
SequenStack<T>::SequenStack(const SequenStack<T>& sstack) {
    stackMax = sstack.capaticty();
    data = new T [stackMax];
    for(int i=0; i< sstack.size(); i++)
    {
        data[i] = sstack[i];
    }
}

template <class T>
typename SequenStack<T>::Status SequenStack<T>::push(T val) {
    Status st = OK;
    if(top != stackMax){
        data[++top] = val;
    }else {
        cout << "stack full" <<endl ;
        st = Warning;
    }
    return st;
}

template <class T>
T SequenStack<T>::pop() {
    int val = 0;
    if (top != -1) {
        val = data[top--];
    }else {
        cout << "empty stack" <<endl;
    }
    return val;
}
template <class T>
SequenStack<T>::~SequenStack(){
    if(data != nullptr) {
        delete [] data;
        top = -1;
        stackMax = 0;
    }
}
template <class U> 
ostream& operator<<(ostream& os, const SequenStack<U>& sstack) {
    int length = sstack.size();
    for(int i= length-1; i>=0; i-- )
    {
        os << sstack.data[i] << " ";
    }
    return os;
}
#endif