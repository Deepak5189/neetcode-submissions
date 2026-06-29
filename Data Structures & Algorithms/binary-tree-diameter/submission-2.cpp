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
    int maxdepth=0;
    int solve(TreeNode* root){
        if(!root) return 0;

        int leftDepth=solve(root->left);
        int rightDepth=solve(root->right);
        maxdepth=max(maxdepth, leftDepth+rightDepth);
        return 1+max(leftDepth, rightDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        solve(root);
        return maxdepth;
    }
};
