class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void backtrack(vector<int>& nums, int idx){
        ans.push_back(cur);

        for(int i=idx; i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;

            cur.push_back(nums[i]);
            backtrack(nums, i+1);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));
        backtrack(nums, 0);
        return ans;
    }
};
