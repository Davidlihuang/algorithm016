/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //三种方法实现:
 /*
 * 1、递归
 * 2、栈
 * 3、广度优先(层遍历修改)
 */
#include <stack>
class Solution {
public:
    int recursionDFS(TreeNode* root);
    int iterDFS(TreeNode* root);
    int iterBFS(TreeNode* root); 
    int maxDepth(TreeNode* root) {
        int d = 0;
        //d = recursionDFS(root);
        //d = iterDFS(root);
        d = iterBFS(root);
        return d;
    }
};
int Solution::recursionDFS(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    // int lf = maxDepth(root->left) + 1;
    //int rt = maxDepth(root->right) + 1;
    //return (lf > rt) ? lf : rt;
    return max(maxDepth(root->left), maxDepth(root->right))+1;
}
int Solution::iterDFS(TreeNode* root) {
    if (root == NULL) return 0;
    stack<pair<TreeNode*, int>> s;
    TreeNode* p = root;
    int Maxdeep = 0, deep = 0;
    while(!s.empty() || p!= NULL) {
        while(p != NULL) {
            s.push(pair<TreeNode*, int>(p, ++deep));
            p = p->left;
        }
        p = s.top().first;
        deep =s.top().second;
        if(Maxdeep < deep) Maxdeep = deep;
        s.pop();
        p = p->right;
    }
    return Maxdeep;
}
int Solution::iterBFS(TreeNode* root) {
    if (root == NULL) return 0;
    deque<TreeNode*> que;
    que.push_back(root);
    int deep = 0;
    while(!que.empty()) {
        deep++;
        int num = que.size();
        for (int i = 1; i <= num; i++) {
            TreeNode* p = que.front();
            que.pop_front();
            if(p->left) que.push_back(p->left);
            if(p->right) que.push_back(p->right);

        }
    }

    return deep;
}