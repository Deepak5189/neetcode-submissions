class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l=0, r=0, maxl=0;
        while(r<s.size()){
            mp[s[r]]++;
            int maxfreq=0;
            for(auto &v:mp){
                maxfreq=max(maxfreq, v.second);
            }
            while(r-l-maxfreq+1>k){
                mp[s[l++]]--;
                for(auto &v:mp){
                maxfreq=max(maxfreq, v.second);
                }
            }
            maxl=max(r-l+1, maxl);
            r++;
        }
        return maxl;
    }
};
