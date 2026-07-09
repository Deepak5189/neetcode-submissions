class Solution {
public:
    vector<string> ans;
    void backtrack(string cur, int open, int close,int& n){
        if(cur.size() == 2*n){
            ans.push_back(cur);
            return;
        }

        if(open<n){
            backtrack(cur+"(", open+1, close, n);
        }
        if(close<open){
            backtrack(cur+")", open, close+1, n);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        int open=0, close=0;
        backtrack("", 0, 0, n);
        return ans;
    }
};
