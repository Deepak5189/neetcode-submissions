class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq=0, ans=0;
        vector<int> freq(26, 0);
        int i=0, j=0, n=s.size();

        while(j<n){
            freq[s[j]-'A']++;
            maxFreq=max(maxFreq, freq[s[j]-'A']);
            while(j-i+1 - maxFreq >k){
                freq[s[i]-'A']--;
                maxFreq=0;
                for(auto&f:freq){
                    maxFreq=max(maxFreq, f);
                }
                i++;
            }
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
