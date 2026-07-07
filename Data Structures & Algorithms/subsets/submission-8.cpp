class Solution {
public:
    void solve(vector<int> &nums, vector<int>& vec, vector<vector<int>>& res, int i){
        if(i==nums.size()){
            res.push_back(vec);
            return;
        }

        vec.push_back(nums[i]);
        solve(nums, vec, res, i+1);
        vec.pop_back();
        solve(nums, vec, res, i+1);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        solve(nums, vec, res, 0);
        return res;
    }
};
