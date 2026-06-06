class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i=0;i<nums.size();i++){
            int j=i+1, k=nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    st.insert({nums[i], nums[j], nums[k]});
                    j++, k--;
                }else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }else j++;
            }
        }
        vector<vector<int>> res;
        for(auto&s:st) res.push_back(s);
        return res;
    }
};
