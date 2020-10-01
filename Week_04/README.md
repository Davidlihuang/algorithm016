# 第四周学习笔记
# 数据结构基础知识
## **图**
###  图的五种存储结构
1. 邻接矩阵
2. 邻接表
3. 十字链表
4. 邻接多重表
5. 边集数组
### 图的创建
1. 邻接矩阵
2. 邻接表
### 图的遍历

1. 深度优先(DFS)
   深度优先遍历类似于树的前序遍历。只能遍历任意顶点之间是相通的连通图，也就是说深度遍历只能作用于包含该顶点的连通分量。对于非连通的图，只需要对图的所有连通分量进行深度遍历。
- (1). DFS步骤
-- ①、指定一个顶点 Vi,  并将其标记为以遍历的状态visited[i] = true
-- ②、对顶点vi的数据进行处理，也可以只是打印显示
-- ③、对顶点Vi的所有未被访问国的邻接节点进行递归调用DFS。
- (2). 代码实例
-- ①、邻接矩阵
```cpp
/* 邻接矩阵的深度优先递归算法 */
bool visited[MAX];
void DFS(const MGraph &G, int i){
    visited[i] = True;
    std::cout << G.vexs[i] <<std::endl;
    for(int j =0; j< G.numVertexes; j++) {
        if (G.arc[i][j] ==  1 && !visited[j]) {
            DFS(G,j);
        }
    }
}
/* 邻接矩阵的深度遍历操作 */
void DFSTraverse(const MGraph &G) {
    for(int i =0; i< G.numVertexes; i++) {
        visited[i] = false;
    }
    for(int j =0; j<G.numVertexes; j++) {  
        if(!visited[j]){
            DFS(G, j);
        }
    }
}
```
-- ②、邻接表
```cpp
/* 邻接表的深度优先递归算法 */ 
void DFS(const GraphAdjList &GL, int i) {
    EdgeNode *p; visited[i] = TRUE; /* 打印顶点，也可以其他操作 */ 	       printf("%c ", GL->adjList[i].data); 
    p = GL->adjList[i].firstedge; 
	while (p) {
        if (!visited[p->adjvex]) /* 对为访问的邻接顶点递归调用 */ 	               DFS(GL, p->adjvex);
        p = p->next; 
    }
}
/* 邻接表的深度遍历操作 */ 
void DFSTraverse(const GraphAdjList &GL) {
    int i; 
    // 初始所有顶点状态都是未访问过的状态
    for (i = 0; i < GL->numVertexes; i++) {
        visited[i] = FALSE;
    }
    // 对未访问过的顶点调用DFS，若是连通图，只会执行一次
    for (i = 0; i < GL->numVertexes; i++) {
        if (!visited[i]) {
            DFS(GL, i);
        }        
    }
}
```

2. 广度优先（BFS）
广度优先遍历类似于树的层遍历，需要借助队列实现
- (1). BFS步骤:
- (2). BFS实现：
--①. 邻接矩阵
```cpp
/*邻接矩阵广度优先算法*/
void BFSTraverse(const MGraph& G) {
    int i, j;
    Queue Q;
    for(i = 0; i< G.numVertexes; i++) {
    	visited[i] = false;
    }
    InitQueue(&Q);
    
    //对每一个顶点做循环, 确保每一个连通分量都被遍历
    for(i = 0; i < G.numVertexes; i++) {
    	if(!visited[i]) {
    		visited[i] = true;
    		std::cout << G.vexs[i] <<std:: endl;
    		EnQueue(&Q, i); 
    		while (!QueueEmpty(Q)) {
    			DeQueue(&Q, i); //队首元素出队,赋值给i
    			for(j =0; j < G.numVexes; j++) {
    			    if(G.arc[i][j] == 1 && !visited[j]) {
    			        visited[j] = true;
    			        std::cout << G.vexs[j] <<std::endl;
    			        EnQueue(&Q, j);
    			    }
    			}
    		}
    	}
    }

}
```
--②. 邻接表
```cpp
/* 邻接表的广度遍历算法 */ 
void BFSTraverse(GraphAdjList GL) {
    int i; 
    EdgeNode *p; 
    Queue Q; 
    for (i = 0; i < GL->numVertexes; i++) 
        visited[i] = FALSE;
    InitQueue(&Q); 
    for (i = 0; i < GL->numVertexes; i++) {
        if (!visited[i]) {
            visited[i] = TRUE; /* 打印顶点，也可以其他操作 */
            printf("%c ", GL->adjList[i].data); 
            EnQueue(&Q, i);                 
            while (!QueueEmpty(Q)) {
                DeQueue(&Q, &i); /* 找到当前顶点边表链表头指针 */ 
                p = GL->adjList[i].firstedge; 
                while (p) {
                    /* 若此顶点未被访问 */ 
                    if (!visited[p->adjvex]) {
                        visited[p->adjvex] = TRUE; 
                        printf("%c ", GL->adjList[p->adjvex].data);                         /* 将此顶点入队列 */ 
                        EnQueue(&Q, p->adjvex);
                } /* 指针指向下一个邻接点 */ 
                p = p->next;
        } 
    } 
}
```
### 最小生成树
1. Prim-普里姆
   1. 关键是更新最小代价数组中的边。
   2. 代码实现
```cpp
/* Prim算法生成最小生成树 */ 
void MiniSpanTree_Prim(MGraph G) {
    int min, i, j, k; /* 保存相关顶点下标 */ 
    int adjvex[MAXVEX]; /* 保存相关顶点间边的权值 */ 
    int lowcost[MAXVEX]; /* 初始化第一个权值为0，即v0加入生成树 */ 
    /* lowcost的值为0，在这里就是此下标的顶点已经加入生成树 */ 
    lowcost[0] = 0; /* 初始化第一个顶点下标为0 */ 
    adjvex[0] = 0; /* 循环除下标为0外的全部顶点 */ 
    for (i = 1; i < G.numVertexes; i++) {
    /* 将v0顶点与之有边的权值存入数组 */ 
        lowcost[i] = G.arc[0][i]; /* 初始化都为v0的下标 */ 
        adjvex[i] = 0;
    } 
    for (i = 1; i < G.numVertexes; i++) {
        /* 初始化最小权值为∞， */ 
        /* 通常设置为不可能的大数字如32767、65535等 */ 
        min = INFINITY; 
        j = 1; 
        k = 0; 
        /* 循环全部顶点 */ 
        while (j < G.numVertexes) {
        /* 如果权值不为0且权值小于min */ 
        if (lowcost[j] != 0 && lowcost[j] < min) {
        /* 则让当前权值成为最小值 */ 
        min = lowcost[j]; 
        /* 将当前最小值的下标存入k */ 
        k = j;
        } 
        j++;
    } /* 打印当前顶点边中权值最小边 */ 
    printf("(%d,%d)", adjvex[k], k); 
    /* 将当前顶点的权值设置为0，表示此顶点已经完成任务 */ 
    lowcost[k] = 0; /* 循环所有顶点 */ 
    for (j = 1; j < G.numVertexes; j++) {
        /* 若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值 */ 
        if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
        /* 将较小权值存入lowcost */
        lowcost[j] = G.arc[k][j]; 
        /* 将下标为k的顶点存入adjvex */ 
        adjvex[j] = k;
        } 
    } 
}
```
2. Kruskal-克鲁斯卡尔

### 最短路径 
1. DijKstra-迪杰斯特拉算法
2. Floyd-弗洛伊德算法
### 拓扑排序

### 关键路径
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
