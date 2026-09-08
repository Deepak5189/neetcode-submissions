class Solution {
public:
    bool isAnagram(string s, string t) {
        if(ssize(s)!=ssize(t)) return false;
        vector<int>freq_s(26, 0);
        vector<int>freq_t(26, 0);
        for(int i=0;i<ssize(s);i++){
            freq_s[s[i]-'a']++;
            freq_t[t[i]-'a']++;
        }

        return freq_s==freq_t;
    }
};
