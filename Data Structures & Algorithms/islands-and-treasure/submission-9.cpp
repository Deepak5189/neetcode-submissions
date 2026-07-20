class Solution {
public:
    int m, n;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        queue<pair<int, int>> st;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==0)
                    st.push({i, j});
        
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!st.empty()){
            auto [i, j] = st.front();
            st.pop();

            
            for(auto& d:dirs){
                int nx=i+d[0], ny=j+d[1];

                if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=INT_MAX){
                    continue;
                }
                grid[nx][ny]=grid[i][j]+1;
                st.push({nx, ny});
            }
        }
        return;
    }
};
