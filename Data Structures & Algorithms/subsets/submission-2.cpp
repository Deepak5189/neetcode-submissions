class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> &nums, int i, vector<int>vec){
        if(i==nums.size()){
            res.push_back(vec);
            return;
        }
        solve(nums, i+1, vec);
        vec.push_back(nums[i]);
        solve(nums, i+1, vec);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        solve(nums, 0, vec);
        return res;
    }
};
