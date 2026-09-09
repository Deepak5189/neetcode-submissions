class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(auto&n:nums){
            if(mp.count(n-1)>0){
                mp[n]=mp[n-1]+1;
                ans=max(ans, mp[n]);
            }else{
                mp[n]=1;
                ans=max(ans, mp[n]);
            }
        }
        return ans;
    }
};
