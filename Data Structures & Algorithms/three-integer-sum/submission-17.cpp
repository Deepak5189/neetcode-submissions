class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i++){
            int j=i+1, k=nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k] <0){
                    j++;
                }else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }else{
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++, k--;
                }
            }
        }
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};
