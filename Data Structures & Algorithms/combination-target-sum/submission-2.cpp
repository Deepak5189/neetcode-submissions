class Solution {
public:
    void solve(vector<int>& nums, vector<int>& vec, int sum, vector<vector<int>>& res, int& target, int i){
        if(sum==target){
            res.push_back(vec);
            return;
        }
        if(i==nums.size() || sum>target){
            return;
        }

        vec.push_back(nums[i]);
        solve(nums, vec, sum+nums[i], res, target, i);
        vec.pop_back();
        solve(nums, vec, sum, res, target, i+1);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> vec;
        int sum=0;
        solve(nums, vec, sum, res, target, 0);

        return res;
    }
};
