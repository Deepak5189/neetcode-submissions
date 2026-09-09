class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i=0, j=0, maxLen=0;
        while(j<s.size()){
            while(st.count(s[j])>0){
                st.erase(s[i++]);
            }
            st.insert(s[j]);
            maxLen=max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};
