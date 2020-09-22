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
    TreeNode* invertTree(TreeNode* root) {
        //recurse terminator
        if (root == NULL)
            return NULL;

        //drill down
        TreeNode* left = invertTree(root->left);
        root->left = invertTree(root->right);
        //process 
        root->right = left;

        return root;
    }
};