#ifndef DOUBLELINKLIST_H_
#define DOUBLELINKLIST_H_
#include <iostream>
using namespace std;

template<class T>
class DoubleList {
private:
    struct ListNode;
    struct ListNode
    {
        T data;
        ListNode* next;
        ListNode* pre;
        ListNode():next(nullptr), pre(nullptr) { }
        ListNode(T val): data(val), next(nullptr), pre(nullptr) { }
        ListNode* insertBeforeNode(const T& val);
        ListNode* insertAfterNode(const T& val);
    };
public:
    enum Status {Error = 0, OK = 1, Warning = 2};
    DoubleList();
    DoubleList(DoubleList<T>& dlist);
    ~DoubleList();
    Status insert(int i, T val);
    Status insertFromHead(T val);
    Status insertFromTail(T val);
    Status remove(int i, T& val);
    Status removeFromHead(T& val);
    Status removeFromTail(T& val);   
    ListNode* getFirstElement();
    ListNode* getLastElement();
    ListNode* getElement(int i);
    ListNode* locateData(T& val);
    Status cycledList();
    bool isCycleList();
    Status clearList();
    DoubleList<T>& operator=(const DoubleList<T>& dlist); 
    ListNode& operator[](int i);
    const ListNode& operator[](int i) const;
    template <class U>
    friend ostream& operator<<(ostream& os, const DoubleList<U>& list);
    
public:
    ListNode* head;
    ListNode* tail;
    int length;
};

template<class T>
typename DoubleList<T>::ListNode* DoubleList<T>::ListNode::insertBeforeNode(const  T& val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = this;
    newNode->pre = this->pre;
    this->pre->next = newNode;
    this->pre = newNode;
    return newNode;
}
template<class T>
typename DoubleList<T>::ListNode* DoubleList<T>::ListNode::insertAfterNode(const T& val) {
    ListNode* newNode = new ListNode(val);
    if (newNode == nullptr) std::cout << "segment false" <<std::endl;
    newNode->next = this->next;
    newNode->pre = this;
    this->next->pre = newNode;
    this->next = newNode;
    return newNode;
}

template<class T>
DoubleList<T>::DoubleList(){
    head = new ListNode;
    tail = new ListNode;
    head->next = tail;
    tail->pre = head;
    length = 0;
}
template<class T>
DoubleList<T>::DoubleList( DoubleList<T>& dlist) {
    head = new ListNode;
    tail = new ListNode;
    head->next = tail;
    tail->pre = head;
    length = 0;
    ListNode* p = dlist.head->next;
    ListNode* newNode = nullptr;
    while(p != dlist.tail) {
        newNode = new ListNode(p->data);
        newNode->pre = tail->pre;
        newNode->next = tail;
        tail->pre->next = newNode;
        tail->pre = newNode;
        length++;
        p = p->next;
    }
}

template<class T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList<T>& dlist) {
    length = dlist.length;
    ListNode* p = dlist.head->next;
    ListNode* newNode = nullptr;
    while(p != dlist.tail) {
        newNode = new ListNode(p->data);
        newNode->pre = tail->pre;
        newNode->next = tail;
        tail->pre->next = newNode;
        tail->pre = newNode;
        length++;
        p = p->next;
    }

    return *this;
}
template<class T>
DoubleList<T>::~DoubleList() {
    clearList();
    if(length == 0) {
        if (head != nullptr && tail != nullptr) {
            delete head;
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
    }
}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::insert(int i, T val) {
    Status st = OK;
    ListNode* p = head;
    ListNode*pcur = nullptr;
    int j = 0 ;
    if (head == nullptr) return Error;
    while (p == tail ||j < i-1) {
        p = p->next;
        j++;
    }
    if (p == tail || j > i-1) {
        st = Error;
        return st;
    }
    pcur = p->insertAfterNode(val);
    if(pcur != nullptr) {
        length++;
    }else {
        st = Error;
    }
    return st;
}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::insertFromHead(T val) {
    Status st = OK;
    ListNode* pcur = nullptr;
    pcur = head->insertAfterNode(val);
    if(pcur != nullptr) {
        length++;
    }else {
        st = Error;
    }

    return st;
}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::insertFromTail(T val) {
    Status st = OK;
    ListNode* pcur = nullptr;
    pcur = tail->insertBeforeNode(val);
    if(pcur != nullptr) {
        length++;
    }else {
        st = Error;
    }
    return st;
}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::remove(int i, T& val) {
    Status st = OK;
    ListNode* p = head;
    ListNode* q = nullptr;
    int j = 0;
    if(head == nullptr || tail == nullptr) return Error;
    while (p->next != tail && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == tail || j > i-1) return Error;
    q = p->next;
    q->next->pre = p;
    p->next = q->next;
    return st;
}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::removeFromHead(T& val) {
    Status st = OK;
    ListNode* p = head;
    ListNode* q = nullptr;
    if (head == nullptr || tail == nullptr) return Error;
    if (head->next != tail) {
        q = head->next;
        head->next = q->next;
        q->next->pre = head;
        val = q->data;
        delete q;
        q = nullptr;
        st = OK;
    } else {
        st = Error;
    }
    return st;
}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::removeFromTail(T& val) {
    Status st = OK;
    ListNode* q = nullptr;
    if (head == nullptr ||tail == nullptr) return Error;
    if (tail->pre != head) {
        q = tail->pre;
        tail->pre = q->pre;
        q->pre->next = tail;
        val = q->data;
        delete q;
        q = nullptr;
        st = OK;
    }
    return st;
}  
template<class T>
typename DoubleList<T>::ListNode* DoubleList<T>::getFirstElement() {
    if(head == nullptr || tail == nullptr) return nullptr;
    if (head->next != tail) {
        return head->next;
    }else {
        return nullptr;
    }
}
template<class T>
typename DoubleList<T>::ListNode* DoubleList<T>::getLastElement() {
    if(head == nullptr || tail == nullptr) return nullptr;
    if(tail->pre != head) {
        return tail->pre;
    }else {
        return nullptr;
    }
}
template<class T>
typename DoubleList<T>::ListNode* DoubleList<T>::getElement(int i) {
    if(head == nullptr || tail == nullptr) return nullptr;
    if (head->next == tail) return nullptr;
    ListNode* p = head->next;
    int j = 1;
    while(p != tail && j < i) {
        p = p->next;
        j++;
    }
    if(p == tail || j > i) return nullptr;
    return p;
}
template<class T>
typename DoubleList<T>::ListNode* DoubleList<T>::locateData(T& val) {
    if (head == nullptr || tail == nullptr) return nullptr;
    if (head->next = tail) return nullptr;
    ListNode* p = head->next;
    int j = 1;
    while(p != tail && p->data != val) {
        p = p->next;
        j++;
    }
    if (p == tail) return nullptr;
    return p;
}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::cycledList() {
    Status st = OK;
    if(head == nullptr || tail == nullptr) return Error;
    head->pre = tail;
    tail->next = head;
    return st;
}
template<class T>
bool DoubleList<T>::isCycleList() {
    if(head == nullptr || tail == nullptr) return false;
    if(head->pre == tail && tail->next == head) {
        return true;
    }else {
        return false;
    }
}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::clearList() {
    Status st = OK;
    if(head == nullptr || tail == nullptr) return Error;
    T data;
    while(length !=0 && st == OK)
    st = removeFromHead(data);
    return st;
}

template<class T>
typename DoubleList<T>::ListNode& DoubleList<T>::operator[](int i) {
    ListNode* p = nullptr;
    p = getElement(i);
    return *p;
}
template<class T>
const typename DoubleList<T>::ListNode& DoubleList<T>::operator[](int i) const {
    ListNode* p = nullptr;
    p = getElement(i);
    return *p;
}
template <class U>
ostream& operator<<(ostream& os, const DoubleList<U>& list) {
    typename DoubleList<U>::ListNode* p = list.head->next;
    os<<"list: ";
    while (p != list.tail)
    {
        os<< p->data <<" ";
        p = p->next;
    }
    return os;
}
#endif
