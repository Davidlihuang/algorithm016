/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //使用前序遍历递归实现
    void pre(TreeNode* root, int depth, vector<vector<int>>& res) {
        if(!root) return;
        if(depth >= res.size())
            res.push_back(vector<int>()); 
        res[depth].push_back(root->val); 
        pre(root->left, depth+1, res);
        pre(root->right, depth+1, res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        //使用队列广度优先搜索实现层序遍历
        vector<vector<int>> res; 
        queue<TreeNode* > Tque;
        if(!root) return res;
        Tque.push(root);
        while(!Tque.empty()) {
            res.push_back(vector<int>());
            int currentLevelSize = Tque.size();
            for(int i=0; i< currentLevelSize; i++) {
                TreeNode* node = Tque.front();
                Tque.pop();
                res.back().push_back(node->val);
                if(node->left) Tque.push(node->left);
                if(node->right) Tque.push(node->right);
            }
        }
        //pre(root, 0, res);
        return res;
    }
};