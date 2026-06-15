class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
        stack<char> st;
        for(auto& c:s){
            if(c==')' || c=='}' || c==']'){
                if(st.empty() || st.top()!=mp[c]) return false;
                st.pop();
            }
            else st.push(c);
        }
        return st.empty();
    }
};