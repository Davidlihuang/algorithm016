#ifndef SKIPLIST_H_
#define SKIPLIST_H_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
typedef int ElementType;
struct Node {
    ElementType data;
    Node* next;
    Node* pre;
    Node* up;
    Node* down;
    Node(ElementType v = INT_MIN)
        :data(v), next(nullptr), 
        pre(nullptr), up(nullptr), down(nullptr) { }
};

class SkipList {  
public:
    SkipList():LevelNum(1) {
        head = new Node();
    }
    void insert(ElementType val);
    void remove(ElementType val);
    bool search(ElementType val);

private:
    Node* head;
    int LevelNum;
    bool randomval();
};
#endif 