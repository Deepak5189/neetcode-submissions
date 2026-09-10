class Solution {
public:
    bool isValid(unordered_map<char, int>& freq_s, unordered_map<char, int>& freq_t){
        for(auto&[a, b]:freq_t){
            if(freq_s[a]<b) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> freq_s, freq_t;
        string res="";
        int ans=INT_MAX, ans_st=0;
        for(auto&c:t) freq_t[c]++;

        int i=0, j=0, n=s.size();

        while(j<n){
            if(freq_t.count(s[j])>0)
                freq_s[s[j]]++;
            while(isValid(freq_s, freq_t)){
                if(j-i+1<ans){
                    ans=j-i+1;
                    ans_st=i;
                }

                if(freq_t.count(s[i])>0) freq_s[s[i]]--;
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? "" : s.substr(ans_st, ans);;
    }
};
