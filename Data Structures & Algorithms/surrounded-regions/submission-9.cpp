class Solution {
public:
    vector<vector<bool>> visited;
    int m, n;
    int dirs[4][2]={{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n || visited[i][j] || board[i][j]=='X'){
            return;
        }
        visited[i][j]=true;
        for(auto&d:dirs){
            int ni=i+d[0], nj=j+d[1];
            dfs(board, ni, nj);
        }
    }

    void solve(vector<vector<char>>& board) {
        m=board.size(), n=board[0].size();
        visited.resize(m, vector<bool>(n, false));

        // dfs for 0s in first row [i=0][j]
        for(int i=0, j=0;j<n;j++){
            if(!visited[i][j] && board[i][j]=='O'){
                dfs(board, i, j);
            }
        }
        // dfs for 0s in last row [i=m-1][j]
        for(int i=m-1, j=0;j<n;j++){
            if(!visited[i][j] && board[i][j]=='O'){
                dfs(board, i, j);
            }
        }

        // dfs for 0s in 1st col [i][j=0]
        for(int i=0, j=0;i<m;i++){
            if(!visited[i][j] && board[i][j]=='O'){
                dfs(board, i, j);
            }
        }
        // dfs for 0s in last col [i][j=n-1]
        for(int i=0, j=n-1;i<m;i++){
            if(!visited[i][j] && board[i][j]=='O'){
                dfs(board, i, j);
            }
        }

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
        return;
    }
};
