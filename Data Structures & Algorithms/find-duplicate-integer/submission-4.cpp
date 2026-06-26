class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev=-1;
        for(auto&n:nums){
            if(prev==n) return n;
            prev=n;
        }

        return -1;
    }
};
