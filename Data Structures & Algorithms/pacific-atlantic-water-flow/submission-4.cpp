class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    void dfs(vector<vector<int>>& heights, int preval, int i, int j, vector<vector<bool>>& visited){
        if(i<0 ||j<0 ||i>=m ||j>=n || visited[i][j]==true){
            return;
        }
        if(heights[i][j]<preval) return;

        visited[i][j]=true;
        for(auto&d:dirs){
            int ni=i+d[0], nj=j+d[1];
            dfs(heights, heights[i][j], ni, nj, visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size(), n=heights[0].size();
        vector<vector<bool>> p_visited(m, vector<bool>(n, false));
        vector<vector<bool>> a_visited(m, vector<bool>(n, false));
        for(int j=0;j<n;j++){
            dfs(heights, INT_MIN, 0, j, p_visited);
            dfs(heights, INT_MIN, m-1, j, a_visited);
        }
        for(int i=0;i<n;i++){
            dfs(heights, INT_MIN, i, 0, p_visited);
            dfs(heights, INT_MIN, i, n-1, a_visited);
        }

        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(p_visited[i][j] && a_visited[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};
