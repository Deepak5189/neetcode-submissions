class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        unordered_map<int, vector<int>> adj;
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>visited(n, false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(auto&c:adj[n]){
                if(!visited[c]){
                    q.push(c);
                    visited[c]=true;
                }
            }
        }
        for(auto&b:visited){
            if(!b) return false;
        }
        return true;
    }
};
