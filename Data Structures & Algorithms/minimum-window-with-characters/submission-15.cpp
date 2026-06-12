class Solution {
public:

    bool isValid(unordered_map<char, int>& mp_s, unordered_map<char, int>& mp_t){
        for(auto& [c, cnt]:mp_t){
            if(mp_s[c]<cnt) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        int i=0, j=0;
        unordered_map<char, int> mp_s;
        unordered_map<char, int> mp_t;
        string res=s+"df";
        for(auto& c:t)mp_t[c]++;
        while(j<s.size()){
            if(mp_t.find(s[j])!=mp_t.end()) mp_s[s[j]]++;
            while(isValid(mp_s, mp_t)){
                if(res.size()>j-i+1) res=s.substr(i, j-i+1);
                if(mp_s.find(s[i])!=mp_s.end()){
                    mp_s[s[i]]--;
                    if(mp_s[s[i]]==0) mp_s.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        if(res==s+"df") return "";
        return res;
    }
};
