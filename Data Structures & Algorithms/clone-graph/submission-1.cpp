/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;

        unordered_map<Node*, Node*> mp;
        stack<Node*> st;
        st.push(node);
        mp[node]=new Node(node->val);

        while(!st.empty()){
            Node* curr=st.top();
            st.pop();

            for(auto&n:curr->neighbors){
                if(!mp.count(n)){
                    mp[n]=new Node(n->val);
                    st.push(n);
                }
                mp[curr]->neighbors.push_back(mp[n]);
            }
        }
        return mp[node];
    }
};
