#include "siglelinklist.h"

/*
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
    int val;
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

template<class U>
std::ostream& operator<<(std::ostream& os, SingleList<U>& list) {
    typename SingleList<U>::ListNode* p = list.head;
    while(p->next) {
        p = p->next;
        os << p->data << " ";
    }
    return os;
}


template<class T>
SingleList<T>::~SingleList() {
    int val;
    clearList();
    if(head->next == nullptr) {
        delete head;
        head = nullptr;
        //std::cout << "release list"<< std::endl;
    }
}
*/