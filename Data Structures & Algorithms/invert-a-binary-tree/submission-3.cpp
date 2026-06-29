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
    void solve(TreeNode* node){
        if(!node->left && !node->right){
            return;
        }
        if(node->left) solve(node->left);
        if(node->right) solve(node->right);
        TreeNode* temp=node->left;
        node->left=node->right;
        node->right=temp;

        return;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        solve(root);
        return root;
    }
};
