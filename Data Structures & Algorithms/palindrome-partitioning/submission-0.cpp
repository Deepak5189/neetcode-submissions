class Solution {
public:
    vector<vector<string>> ans;
    vector<string> cur;
    bool isPalindrome(string s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtrack(string& s, int idx){
        if(idx == s.size()){
            ans.push_back(cur);
            return;
        }

        for(int end=idx;end<s.size();end++){
            string part=s.substr(idx, end-idx+1);

            if(isPalindrome(part)){
                cur.push_back(part);
                backtrack(s, end+1);
                cur.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);

        return ans;
    }
};