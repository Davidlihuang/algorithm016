#include "skipList.h"

static unsigned int seed = 0;
bool SkipList::randomval() {
    if(seed == 0) {
        seed = (unsigned)time(0);
    }
    srand(seed);
    int ret = rand()%2;
    seed = rand();
    if(ret == 0) {
        return true;
    } else {
        return false;
    }
}
/*
1、在最底层找到合适的插入位置插入新元素，插入后序列保证有序
2、当前插入的结点有50%的几率上升一层，上层为空则构建新一层
   若层已存在，查找合适的位置插入上升的结点
3、链接插入结点和上升的结点
ps:上升的层数是随机的，没有确定的层数
*/
void SkipList::insert(ElementType val) {
    Node* cursor = head;
    Node* newNode = nullptr;
    Node* skipNode = nullptr;
    Node* curHead = nullptr;

    while (cursor->down != nullptr) {
        cursor = cursor->down;
    }
    curHead = cursor; //层链表头
    
    //插入新结点
    while (cursor->next != nullptr) {
        if(val < cursor->next->data && newNode != nullptr) {
            newNode = new Node(val);
            newNode->next = cursor->next;
            cursor->next = newNode;
        }
        cursor = cursor->next;
    }
    if (newNode == nullptr) {
        newNode = new Node(val);
        cursor->next = newNode;
    }

    //升维
    int curLevel = 1;
    while (randomval())
    {
        curLevel++;
        if (LevelNum < curLevel) {
            LevelNum++;
            Node* newHead = new Node();
            newHead->down = head;
            head->up = newHead;
            head = newHead;
        }  //更改跳表头

        curHead = curHead->up;
        cursor = curHead;
        //上升结点，插入层
        while (cursor->next != nullptr) {
            if(val < cursor->next->data && skipNode == nullptr) {
                skipNode = new Node(val);
                skipNode->next = cursor->next;
                cursor->next = skipNode;
            }
            cursor = cursor->next;
        }
        if (skipNode == nullptr) {
            skipNode = new Node(val);
            cursor->next = skipNode;
        }

        //链接上下结点
        while (newNode->up != nullptr) {
            newNode = newNode->up;
        }
        skipNode->down = newNode;
        newNode->up = skipNode;
    }
    
      
}

bool SkipList::search(ElementType val) {
    
    //遍历到L1层，如果结点不存在cursor->right和cursor->down
    Node* cursor  = nullptr;
    if (head == nullptr) {
        return false;
    } else {
        cursor = head;
        while (cursor->down != nullptr) {
            while (cursor->next != nullptr)
            {
                if (val <= cursor->next->data) {
                    break;
                }
                cursor = cursor->next;
            }
            cursor = cursor->down;
        }
        //到达L1层
        while (cursor->next != nullptr) {
            if (val > cursor->next->data) {
                cursor = cursor->next;
            } else if (val == cursor->next->data) {
                cursor = cursor->next;
                return true;
            } else {
                return false;
            }
        }
    }
}

void SkipList::remove(ElementType val) {
    Node* cursor = head;
    Node* preHead = nullptr;
    while (true)
    {
        Node* curHead = cursor;
        if (preHead != nullptr) {
            curHead->up = nullptr;
            preHead->down = nullptr;
            delete preHead;
            preHead = nullptr;
            LevelNum--;
            head = curHead;
        }
        while (cursor != nullptr && cursor->next != nullptr)
        {
            if(val == cursor->next->data) {
                Node* deltePtr = cursor->next;
                cursor->next = cursor->next->next;
                delete deltePtr;
            }
            cursor = cursor->next;
        }
        if(curHead->next == nullptr) {
            preHead = curHead;
        }
        if(curHead->down == nullptr) {
            break;
        } else {
            cursor = curHead->down;
        }
        
    }
    
}