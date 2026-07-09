class Solution {
public:
    vector<string> ans;
    string cur;
    void backtrack(int open, int close, int& n){
        if(cur.size()==2*n){
            ans.push_back(cur);
            return;
        }

        if(open<n){
            cur.push_back('(');
            backtrack(open+1, close, n);
            cur.pop_back();
        }

        if(close<open){
            cur.push_back(')');
            backtrack(open, close+1, n);
            cur.pop_back();
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return ans;
    }
};
