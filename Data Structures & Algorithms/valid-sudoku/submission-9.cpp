class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.') continue;
                string row="row"+to_string(i)+"val"+board[i][j];
                string col="col"+to_string(j)+"val"+board[i][j];
                string box = "box" + to_string(i/3) + "-" + to_string(j/3) + "val" + board[i][j];
                if(st.find(row)!=st.end() || st.find(col)!=st.end() || st.find(box)!=st.end()) return false;
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
};
