class Solution {
public:
    vector<vector<int>>res;
    vector<int>vec;
    void solve(vector<int>& nums, int& target, int sum, int i){
        if(target == sum){
            res.push_back(vec);
            return;
        }
        if(i==nums.size() || sum>target){
            return;
        }

        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]) continue;

            vec.push_back(nums[j]);
            solve(nums, target, sum+nums[j], j+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, 0);
        return res;
    }
};
