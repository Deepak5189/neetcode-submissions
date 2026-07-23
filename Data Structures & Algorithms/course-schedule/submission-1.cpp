class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> visited;
    bool isCycle = false;
    void dfs(int a){
        if(visited[a]){
            isCycle=true;
            return;
        }
        visited[a]=true;
        for(auto&b:adj[a]){
            dfs(b);
        }
        visited[a]=false;
        return;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses, false);
        for(auto&p:prerequisites) adj[p[1]].push_back(p[0]);
        for(int i=0;i<numCourses;i++){
            if(isCycle) return false;
            dfs(i);
        }
        return true;
    }
};
