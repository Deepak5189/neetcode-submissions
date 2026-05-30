class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto& s:strs){
            vector<int> hash(26, 0);
            for(char &c:s) hash[c-'a']++;
            string strHash="";
            for(auto&n:hash) strHash+=to_string(n)+",";
            mp[strHash].push_back(s);
        }
        vector<vector<string>> res;
        for(auto &val:mp){
            res.push_back(val.second);
        }
        return res;
    }
};
