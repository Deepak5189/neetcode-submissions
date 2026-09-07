class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // cout<<nums.size()-1<<endl;
        // if(nums.size()==0) return false;
        sort(nums.begin(), nums.end());
        for(int i=0;i<ssize(nums)-1;i++){
            cout<<i<<" "<<nums.size()-1<<endl;
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};