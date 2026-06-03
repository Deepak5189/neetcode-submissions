class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        unordered_set<int> st;
        for(auto &num:nums) st.insert(num);
        int len=0, maxlen=0;
        for(auto s:st){
            if(st.find(s-1)==st.end()){
                int b=s;
                // len++;
                while(st.find(b++)!=st.end()){
                    len++;
                }
                maxlen=max(maxlen, len);
                len=0;
            }
        }

        return maxlen;
    }
};
