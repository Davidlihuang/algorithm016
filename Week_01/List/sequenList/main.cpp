#include <iostream>
#include <vector>
#include "sequenlist.h"

int main()
{
    using namespace std;
    SequenList sqlist;

    for(int i=0; i<10; i++) {
        sqlist.addtail(i+1);
    }
    for(int i=0; i<10; i++) {
        sqlist.addfirst(i+1);
    }
    cout << sqlist <<endl;
    int val;
    cout<<"remove tail"<<endl;
    while (sqlist.listLength() != 10)
    {
        cout << sqlist <<endl; 
        sqlist.removeTail(val);
    }
    cout<<"remove first"<<endl;
    while (sqlist.listLength() != 0)
    {
        cout << sqlist <<endl; 
        sqlist.removeFirst(val);
    }
    return 0;
}