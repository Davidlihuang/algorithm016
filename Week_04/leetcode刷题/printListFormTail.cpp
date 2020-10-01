/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    //1、使用递归的实现
    void recursionHelper(ListNode* head, vector<int>& res) {
        ListNode* p = head;
        if(p == NULL) return;
        recursionHelper(p->next, res);
        res.push_back(p->val);
    }
    vector<int> Helper(ListNode* head,vector<int>& res) {
        if(head == NULL) return res;
        Helper(head->next, res);
        res.push_back(head->val); 
        return res;
    }
    //2、使用栈实现
    void stackHelper(ListNode* head, vector<int>& res) {
        ListNode* p = head;
        stack<int> st;
        while(p != NULL) {
            st.push(p->val);
            p = p->next;
        }
        while(!st.empty()) {
            int val = st.top();
            st.pop();
            res.push_back(val);
        }
    }
    //3、使用vector反转
    void reverseVetor(ListNode* head, vector<int>& res) {
        while(head) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
    }
    //4、更改链表结构，更改指针的指向，原链表的尾结点成为头节点
    void changeLinkList(ListNode**head,vector<int>& res) {
        ListNode* pre = NULL;
        ListNode* cur = *head;
        ListNode* next = *head;
        while(cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        while (pre) {
            res.push_back(pre->val);
            pre = pre->next;
        }
    }

    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        //stackHelper(head, res);
        reverseVetor(head, res);
        //changeLinkList(&head, res);
        //recursionHelper(head, res);
        /*
        //5、直接法： 求链表长度，然后创建大小和链表长度相当的容器。再次遍历链表将所有的元素从n填到0;
        int n = 0;
        ListNode* p = head;
        while (p != NULL) {
            n += 1;
            p = p->next;
        }
        vector<int> res(n, 0);

        p = head;
        while(p && n>=0) {
            res[--n] = p->val;
            p = p->next;
        }
        return res;
        */
        /*
        vector<int> res;
        res = Helper(head,res);
        return res;
        */
        return res;
    }
};