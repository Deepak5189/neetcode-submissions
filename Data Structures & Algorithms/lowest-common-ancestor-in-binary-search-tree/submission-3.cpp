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
bool reachedP, reachedQ;
    void canReach(TreeNode* root, TreeNode* p, TreeNode* q){
        if(reachedP && reachedQ) return;
        if(!root) return;
        if(root==p) reachedP=true;
        if(root==q) reachedQ=true;
        canReach(root->left, p, q);
        canReach(root->right, p, q);
        return;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca=nullptr;
        queue<TreeNode*>que;
        que.push(root);

        while(!que.empty()){
        TreeNode* cur=que.front();
        que.pop();
        reachedP=false, reachedQ=false;
        canReach(cur, p, q);
        if(reachedP && reachedQ){
            lca=cur;
        }
        if(cur->left) que.push(cur->left);
        if(cur->right) que.push(cur->right);
        }

        return lca;
    }
};
