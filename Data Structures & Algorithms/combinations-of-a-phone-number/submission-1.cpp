class Solution {
public:
    vector<string> ans;
    unordered_map<char, vector<char>> mp;

    void solve(string& cur, string& digits){
        if(cur.size()==digits.size()){
            ans.push_back(cur);
            return;
        }
        int pos=cur.size();
        for(auto&c:mp[digits[pos]]){
            cur.push_back(c);
            solve(cur, digits);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return ans;
        mp['2']={'a', 'b', 'c'};
        mp['3']={'d', 'e', 'f'};
        mp['4']={'g', 'h', 'i'};
        mp['5']={'j', 'k', 'l'};
        mp['6']={'m', 'n', 'o'};
        mp['7']={'p', 'q', 'r', 's'};
        mp['8']={'t', 'u', 'v'};
        mp['9']={'w', 'x', 'y', 'z'};
        string temp;
        solve(temp, digits);
        return ans;
    }
};