class Solution {
public:
    int m, n;
    bool isValid(int i, int j){
        if(i<0 || j<0 || i>=m || j>=n){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        queue<pair<int, int>> q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }
        int time=0;
        vector<vector<int>> dirs={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            int n=q.size();
            bool changed=false;
            cout<<n<<endl;
            while(n--){
                auto [x, y] = q.front();
                q.pop();
                for(auto&d:dirs){
                    int nx = x+d[0], ny=y+d[1];
                    if(isValid(nx, ny)){
                        if(grid[nx][ny]==1){
                            grid[nx][ny]=2;
                            fresh--;
                            q.push({nx, ny});
                            changed=true;
                        }
                    }
                }
            }
            if(changed) time++;
        }
        if(!fresh) return time;
        return -1;
    }
};
