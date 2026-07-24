class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        queue<int>q;
        for(auto&p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(!indegree[i]) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            ans.push_back(a);
            for(auto&n:adj[a]){
                indegree[n]--;
                if(!indegree[n]) q.push(n);
            }
        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};
