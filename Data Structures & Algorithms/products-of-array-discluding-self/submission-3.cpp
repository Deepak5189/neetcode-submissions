class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_res(nums.size(), 1);
        vector<int> right_res(nums.size(), 1);
        for(int i=1;i<nums.size();i++){
            left_res[i]=left_res[i-1]*nums[i-1];
        }
        for (int i=nums.size()-2;i>=0;i--){
            right_res[i]=right_res[i+1]*nums[i+1];
        }

        for(int i=0;i<nums.size();i++){
            left_res[i]*=right_res[i];
        }

        return left_res;
    }
};
