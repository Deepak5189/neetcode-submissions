class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(auto& s:strs){
            vector<int> strHash(26, 0);
            for(char &c:s) strHash[c-'a']++;
            mp[strHash].push_back(s);
        }
        vector<vector<string>> res;
        for(auto &val:mp){
            res.push_back(val.second);
        }
        return res;
    }
};
