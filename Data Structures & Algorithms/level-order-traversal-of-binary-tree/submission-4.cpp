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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        // answer vector for return
        vector<vector<int>> ans;
        // a queue which will be used to access elements in level order
        queue<TreeNode*> q;
        // push root in the queue
        q.push(root);

        // until q gets empty do this: 
        // check how many elements are there in this level
        // remove exact these elements in order and push in a temp array
        // then push this array in ans
        // if any of these elements are not leaf node then push their children in q
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
