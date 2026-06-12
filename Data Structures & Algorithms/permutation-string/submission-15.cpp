class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()> s2.size()) return false;
        unordered_map<char, int> mp1;
        for(auto& c:s1) mp1[c]++;

        int i=0, j=0;
        unordered_map<char, int> mp2;
        while(j<s1.size()){
            mp2[s2[j++]]++;
        }
        while(j<s2.size()){
            if(mp1==mp2) return true;
            mp2[s2[j++]]++;
            mp2[s2[i]]--;
            if(mp2[s2[i]]==0) mp2.erase(s2[i]);
            i++;
        }
        return mp1==mp2;
    }
};
