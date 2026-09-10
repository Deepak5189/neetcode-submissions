class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq_s, freq_t;
        int required=0, min_len=INT_MAX, min_len_start=0;
        for(char&c:t){
            if(!freq_t.count(c)){
                required++;
            }
            freq_t[c]++;
        }

        int i=0, j=0, n=s.size();

        while(j<n){
            if(freq_t.count(s[j])){
                freq_s[s[j]]++;
                if(freq_s[s[j]]==freq_t[s[j]]){
                    required--;
                }
            }
            while(!required){
                if(j-i+1<min_len){
                    min_len=j-i+1;
                    min_len_start=i;
                }
                
                if(freq_t.count(s[i])){
                    freq_s[s[i]]--;
                    if(freq_s[s[i]]<freq_t[s[i]]) required++;
                }
                i++;
            }
            j++;
        }
        return min_len==INT_MAX ? "" : s.substr(min_len_start, min_len);
    }
};
