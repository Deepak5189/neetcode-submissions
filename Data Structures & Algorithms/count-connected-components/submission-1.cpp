class Solution {
public:
    vector<bool> visited;
    unordered_map<int, vector<int>> adj;
    void dfs(int i){
        if(visited[i]) return;
        visited[i]=true;
        for(auto&n:adj[i]){
            dfs(n);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        visited.resize(n, false);
        int comp=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                comp++;
                dfs(i);
            }
        }
        return comp;
    }
};
