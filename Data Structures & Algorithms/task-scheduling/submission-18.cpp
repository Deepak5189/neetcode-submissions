class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq=0;
        for(auto&t:tasks){
            freq[t-'A']++;
            maxFreq=max(maxFreq, freq[t-'A']);
        }
        int cnt=0;
        for(auto& f:freq) if(f==maxFreq) cnt++;

        return max((int)tasks.size(), ((maxFreq-1)*(n+1)) + cnt);
    }
};
