class Solution {
public:
    vector<vector<string>> ans;
    vector<string> cur;

    bool isValid(int row, int col, int n){
        if(row==0) return true;
        // vertically upward
        for(int i=0;i<row;i++){
            if(cur[i][col]=='Q') return false;
        }
        // diagonally left
        int i=row-1, j=col-1;
        while(i>=0 && j>=0){
            if(cur[i][j]=='Q') return false;
            i--; j--;
        }
        // diagonally right
        i=row-1, j=col+1;
        while(i>=0 && j<n){
            if(cur[i][j]=='Q') return false;
            i--; j++;
        }

        return true;
    }

    void solve(int n, int row){
        if(row>=n){
            ans.push_back(cur);
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(row, col, n)){
                cur[row][col] = 'Q';
                solve(n, row+1);
                cur[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        cur.resize(n, string(n, '.'));
        solve(n, 0);
        return ans;
    }
};