# 第四周学习笔记
## 课程内容学习
### 深度与广度优先遍历
#### 代码模板
1.深度优先
```cpp
//递归写法
map<int, int> visited;
void DFS(Node* root) {
    //terminal
    if(!root) return;
    if(visited.count(root->val)) {
        //already visited
        return;
    }
    visited[root->val] = 1; // add current node to visited
    
    //process current node here
    //...
    for(int i=0; i<root->child.size(); ++i) {
         DFS(root->children[i]);
    }
    return ;
}

//迭代写法， 手动维护一个栈
void DFS(Node* root) {
    map<int, int> visited;
    if(!root) return;
    
    stack<Node*> stackNode;
    stackNode.push(root);
    
    while (!stackNode.empty()) {
        Node* node = stackNode.top();
        StackNode.pop();
        if(visited.count(node->val)) continue;
        visited[node->val] = 1;
        for(int i = node-> children.size()-1; i>=0; i--) {
            StackNode.push(node->children[i]);
        }
    }
    return;
}
```
2.广度优先
```cpp
void BFS(Node* root) {
    map<int, int> visited;
    if(!root) return;
    queue<Node*> queueNode;
    queueNode.push(root);
    while(!queueNode.empty()) {
        Node* node = queueNode.top();
        queueNode.pop();
        if(visited.count(node->val)) continue;
        visited[node->val] = 1;
        
        for(int i=0; i< node->children.size(); i++) {
           queueNode.push(node->children[i]);
        }
    }
    return;
}
```
### 贪心算法
#### 定义
贪心算法时一种在每一步选择中都采取在当前状态下最好或最优的选择，以希望导致结果是全局最好或最优的算法。
#### 与动态规划的区别
贪心算法会对每一个子问题的解决方案都做出最优选择，不能回退。而动态规划会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能。
1. 贪心：当下做出局部最优判断，且不会回退
2. 回溯： 能够回退
3. 动态规划： 最优判断+回退 
#### 应用方向
1. 解决最优化问题：如最小生成树， 哈夫曼编码等。对工程和生活中的问题，一般得不到最优答案
2. 一个问题可以通过贪心算法解决， 那么贪心算法一般是解决这个问题的最好方法
3. 用作辅助算法或者直接解决一些要求结果不是特别精确的问题
#### 适用于贪心算法的场景
一个问题能够分解成子问题来解决， 子问题的最优解能够地推到最终问题的最优解，这种子问题的最优解称为最优子结构
#### 贪心角度
1. 直接使用贪心
2. 问题转化后用贪心
3. 从前往后贪
4. 从后往前贪
#### 相关题目
1. 分发饼干
2. 买卖股票最佳时机II
3. 跳跃游戏I， II
4. 柠檬水找零
5. 模拟行走机器人
### 二分查找
#### 前提
1. 目标函数单调性(单调递增或者单调递减) -- 有序
2. 存在上下界(bounded)
3. 能够通过索引访问(index accessible)
#### 算法注意细节
二分查找在边界条件上比较容易出错，算法框架如下所示。
循环结束条件：
- $\leq$ : 搜索区间为闭区间 [left, right]其中right =  array.length -1;
-- ①、搜索左边区间时：right = mid-1;
-- ②、搜索右边区间时：left   = mid+1;
- $<$: 搜索区间左闭右开：[left, right) 其中right = array.length
-- ①、搜索左半区间：right = mid;
-- ②、搜索右半区间：left   = mid +1;
#### 算法框架
```cpp
//迭代
int binarySearch(int[] nums, int target) {
    int left = 0, right = ...;
    while(...) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            ...
        } else if (nums[mid] < target) {
            left = ...
        } else if (nums[mid] > target) {
            right = ...
        }
    }
    return ...;
```
#### 常用场景
1. 寻找一个数
```cpp
//迭代
int binarySearch(int[] nums, int target) {
    int left = 0, right = len-1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid+1;
        } else if (nums[mid] > target) {
            right = mid-1;
        }
    }
    return -1;
```
2. 寻找左侧边界: 
- 开区间[left, right）
```cpp
int binarySearch_LeftBound(int[] nums, int target) {
    int left = 0, right = len;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid+1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    return left;
```
- 闭区间：[left, right] 应该检查越界情况
```cpp
//迭代
int binarySearch_LeftBound(int[] nums, int target) {
    int left = 0, right = len-1;   //闭区间
    while(left <= right) {   //终止条件
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid-1;  //锁定左边界
        } else if (nums[mid] < target) {
            left = mid+1;
        } else if (nums[mid] > target) {
            right = mid-1;
        }
    }
    //增加判定left越界条件
    if(left >= len || nums[left] != target) return -1
    return left;
}
```
3. 寻找右侧边界
- 开区间[left, right）：left = mid+1; right = mid；保证左闭右开
```cpp
int binarySearch_RightBound(int[] nums, int target) {
    int left = 0, right = len;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1;  //锁定右边界
        } else if (nums[mid] < target) {
            left = mid+1;   //左闭
        } else if (nums[mid] > target) {
            right = mid;    //右开
        }
    }
    return left-1; //注意
}
```
- 闭区间：[left, right] 应该检查越界情况
```cpp
int binarySearch_RightBound(int[] nums, int target) {
    int left = 0, right = len-1;   //闭区间
    while(left <= right) {   //终止条件
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid+1;
        } else if (nums[mid] < target) {
            left = mid+1;   //左闭
        } else if (nums[mid] > target) {
            right = mid-1;	//右闭
        }
    }
    //增加判定越界条件
    if(right < 0 || nums[right] != target) return -1；
    return right;
}
```
#### 使用闭区间的二分查找算法模板
```cpp
//查找一个数
int binarySearch(int[] nums, int target) {
    int left = 0, right = len-1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid+1;
        } else if (nums[mid] > target) {
            right = mid-1;
        }
    }
    return -1;
}
//查找左边界
int binarySearch_LeftBound(int[] nums, int target) {
    int left = 0, right = len-1;   //闭区间
    while(left <= right) {   //终止条件
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid-1;  //锁定左边界
        } else if (nums[mid] < target) {
            left = mid+1;
        } else if (nums[mid] > target) {
            right = mid-1;
        }
    }
    //增加判定left越界条件
    if(left >= len || nums[left] != target) return -1
    return left;
}
//查找右边界
int binarySearch_RightBound(int[] nums, int target) {
    int left = 0, right = len-1;   //闭区间
    while(left <= right) {   //终止条件
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid+1;
        } else if (nums[mid] < target) {
            left = mid+1;   //左闭
        } else if (nums[mid] > target) {
            right = mid-1;	//右闭
        }
    }
    //增加判定越界条件
    if(right < 0 || nums[right] != target) return -1；
    return right;
}
```
## **leetcode刷题**
### 1、从尾到头打印链表
#### 方法
1. 直接法
2. 递归
3. 使用算法库reverse
4. 使用stack
5. 更改链表结构，更改链表指针指向
#### 代码
```cpp
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
    //5、直接法： 求链表长度，然后创建大小和链表长度相当的容器。再次遍历链表将所有的元素从n填到0;
    vector<int> directly(ListNode* head) {
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
    }
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        //stackHelper(head, res);
        //reverseVetor(head, res);
        //changeLinkList(&head, res);
        //recursionHelper(head, res);
        res = directly(head);
        return res;
    }
};

```
### 2、 二叉树中序遍历
#### 代码
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //递归
    void inorderHelper(TreeNode* root, vector<int> &res) {
        if( root ) {
            inorderHelper(root->left, res);
            res.push_back(root->val);
            inorderHelper(root->right,res);
        }
    }
    //借助栈迭代
    void iteraTraversal(TreeNode* root, vector<int>& res) {
        stack<TreeNode* > st;
        TreeNode* p = root;
        while(p != nullptr || !st.empty()) {
            while(p != nullptr) {
                //res.push_back(p->val); //前序
                st.push(p);
                p = p->left;
            }
            
            p = st.top();
            res.push_back(p->val); //中序
            st.pop();
            p = p->right;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        //inorderHelper(root, res);
        //iteraTraversal(root, res);
        if( root ) {
            inorderHelper(root->left, res);
            res.push_back(root->val);
            inorderHelper(root->right,res);
        }
        return res;
    }
};
```

### 3、买卖股票的最佳时机
#### 代码
```cpp

class Solution {
public:
    //暴力解法: 
    int sloveOne(vector<int>& prices)；
    //动态规划
    int solveThree(vector<int>& prices)；
    //一次遍历:时间复杂度O(n), 空间复杂度: O（1）
    int solveTwo(vector<int>& prices)；
    
    int maxProfit(vector<int>& prices) {
       int max = 0;
       //max = sloveOne(prices);
       max = solveTwo(prices);
       //max = solveThree(prices);
       return max;
    }
};

 //暴力解法: 
int Solution::sloveOne(vector<int>& prices) {
    int len = prices.size();
    int MaxPro =0;
    for(int i =0; i < len-1; i++) {
       for(int j = i+1; j< len; j++) {
            int money =prices[j]-prices[i];
            if(money > 0) {
                MaxPro = (money > MaxPro) ? money : MaxPro; 
            }
        }
    }
    return MaxPro;
}
//一次遍历:时间复杂度O(n), 空间复杂度: O（1）
int Solution::solveTwo(vector<int>& prices) {
	int inf = 1e9;
	int minPrice = inf, MaxProfit = 0;
	for(int i = 0; i < prices.size(); i++) {
		MaxProfit = max(MaxProfit, (prices[i]-minPrice));
		minPrice = min(minPrice, prices[i]);
    }
    return MaxProfit;
}    
//动态规划
int Solution::solveThree(vector<int>& prices) {
	int n = prices.size();
    if(n == 0) return 0;
    int minPrice = prices[0];
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++) {
        minPrice = min(minPrice, prices[i]);
        dp[i] = max(dp[i-1], prices[i] - minPrice);
    }
    return dp[n-1];
}

```
### 4、x的平方根
### 5、有效的完全平方数
### 6、搜索旋转排序数组
### 7、搜索二维矩阵
### 8、 寻找旋转排序数组中的最小值
