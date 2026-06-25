class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>cnt(nums.size(), 0);
        for(auto&n:nums){
            if(cnt[n]>0) return n;
            cnt[n]++;
        }

        return -1;
    }
};
