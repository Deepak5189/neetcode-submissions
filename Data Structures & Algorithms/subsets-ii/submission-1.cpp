class Solution {
public:
    set<vector<int>> res;
    vector<int> cur;
    void backtrack(vector<int>& nums, int i){
        if(i==nums.size()){
            res.insert(cur);
            return;
        }
        backtrack(nums, i+1);
        cur.push_back(nums[i]);
        backtrack(nums, i+1);
        cur.pop_back();
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return vector<vector<int>> (res.begin(), res.end());
    }
};
