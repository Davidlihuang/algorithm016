# 第二周学习笔记

## 树
### 二叉树的五个性质
### 二叉树的实现
1. 创建
2. 四种遍历的递归和非递归实现
- ①. 前序遍历
-- 递归实现
-- 迭代实现：需要借助栈来实现
- ②. 中序遍历
-- 递归实现
-- 迭代实现：需要借助栈来实现
- ③. 后序遍历
-- 递归实现
-- 迭代实现：需要借助栈来实现
- ④. 层序遍历
-- 迭代实现：需要借助队列实现
3. 线索化二叉树
二叉树的n个中会有n-1个指针域为空，为了提升内存的利用率，可以将这n-1个为空的指针域用于指向其前驱或则后继，将二叉树线索化为一个链表(链表是树的特殊结构)。、
- 思路：
- 代码示例：
4. 平衡二叉树
5. 排序二叉树

## 图

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





