#include <iostream>
#include "doublelinklist.h"

int main() {
    using namespace std;
    DoubleList<int> dlist1;
    //插入删除测试
    cout << "insert 10 element to dlist1: ";
    for(int i = 1; i<=10; i++) {
        dlist1.insertFromHead(i);
    }
    for(int i = 1; i<=10; i++) {
        dlist1.insertFromTail(i);
    }
    cout << dlist1 << endl;

    dlist1.insert(0,200);
    int val=0;
    dlist1.remove(0,val);
    dlist1.removeFromTail(val);
    dlist1.removeFromHead(val);
    cout << dlist1 << endl;

    //取值
    cout <<"first element: " << dlist1.getFirstElement()->data << endl;
    cout <<"tail element: "<< dlist1.getLastElement()->data << endl;
    for(int i =0; i<dlist1.length; i++) {
        if(dlist1.getElement(i) == nullptr) {
            cout << "nullptr[19]" << endl;
        } else {
            cout<<dlist1.getElement(i)->data << " ";
        }
    }
    cout <<endl;
    cout << dlist1[1].data <<endl;
    dlist1[1].data= 400;
    cout <<dlist1[1].data <<endl;

    cout << (dlist1.isCycleList()?"cycle":"non cycle")<<endl;
    dlist1.cycledList();
    cout << (dlist1.isCycleList()?"cycle":"non cycle")<<endl;
    
    //复制构造和赋值测试
    cout<< "\ncopy and asigment function test: "<<endl;;
    DoubleList<int> dlist2(dlist1);
    cout <<"copy constructor: "<< dlist2 << endl;

    DoubleList<int> dlist3;
    dlist3 = dlist1;
    cout <<"asignment =: "<< dlist3 << endl;
    

    cout << "test end " << endl;
    return 0;
}