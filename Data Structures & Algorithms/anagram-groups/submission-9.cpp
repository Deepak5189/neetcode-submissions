class Solution {
public:
    bool checkAnagrams(string& s, string& t){
        if(s.size()!=t.size()) return false;
        vector<int> arr(26, 0);
        int n=s.size();
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }

        for(int a:arr){
            if(a!=0) return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<bool> visited(strs.size(), false);
        for(int i=0;i<strs.size();i++){
            vector<string> anagrams;
            string s=strs[i];
            if(visited[i]) continue;
            anagrams.push_back(s);
            visited[i]=true;
            for(int j=i+1;j<strs.size();j++){
                string t=strs[j];
                if(visited[j]) continue;
                bool isValid=checkAnagrams(s, t);
                if(isValid){
                    anagrams.push_back(t);
                    visited[j]=true;
                }
            }
            res.push_back(anagrams);
        }
        return res;
    }
};
