#include <iostream>
#include "sequnstack.h"
#include "liststack.h"

using namespace std;
int main() {
    ListStack<int> lstack;
    for (int i=0;i<3;i++) {
        lstack.push(i+1);
    }
    cout << lstack << endl;

    //copy Constructor
    ListStack<int> lstack1(lstack);
    cout << lstack1 << endl;

    //assigned 
    ListStack<int> lstack2;
    lstack2 = lstack1;
    cout << "=: " << lstack2 << endl;
    
    //pop all element
    while(lstack.size()) {
        lstack.pop();
    }
    cout << lstack << endl;

    //sequenList
    SequenStack<int> sstack(10);
    for(int i =0; i<10; i++) {
        sstack.push(i+1);
    }
    cout <<"sstack size:"<<sstack.size()<< " elemet: "<<sstack << endl;
    for(int i =0; i<11; i++) {
        sstack.pop();
        cout <<"sstack size:"<<sstack.size()<< " elemet: "<<sstack << endl;   
    }
    cout << "test ended!" <<endl;
    return 0;
}