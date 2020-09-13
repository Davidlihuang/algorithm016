#include "sequenlist.h"

void SequenList::addfirst(const ElemenType val) {
    insert(0, val);
}
void SequenList::addtail(const ElemenType val) {
    insert(length, val);
}
void SequenList::insert(int i, const ElemenType val) {
    if (i < 0 || i > length) {
        return;
    } else if (length == MAXSIZE) {
        return ;
    } else {
        for(int j = length; j >= i; j--) {
            data[j+1] = data[j];
        }
        data[i] = val;
        length++;
    }
}

void SequenList::removeFirst(ElemenType& val) {
    remove(0,val);
}
void SequenList::removeTail(ElemenType& val) {
    remove(length-1, val);
}
void SequenList::remove(int i, ElemenType& val) {
    if (i < 0 ||i > length-1) {
        return ;
    }else if (length == 0){
        return;
    }else {
        val = data[i];
        for (int j = i; j < length; j++) {
            data[j] = data[j+1];
        }
        length--;
    }
}
ElemenType SequenList::getElement(int i) const {
    if ( i <0 || i > length-1) {
        return -1;
    } else {
        return data[i];
    }
}
int SequenList::locatElement(ElemenType val) {
    for (int i = 0; i < length; i++) {
        if (data[i] == val) {
            return i;
        }
    }
    return -1;
}
ElemenType& SequenList::operator[](int i) {
    return data[i];
}
ElemenType SequenList::operator[](int i) const {
    return data[i];
}

std::ostream& operator<<(std::ostream& os, SequenList &sqlist) {
    for (int i=0; i<sqlist.length; i++) {
        os << sqlist[i] <<" ";
    }
    return os;
}