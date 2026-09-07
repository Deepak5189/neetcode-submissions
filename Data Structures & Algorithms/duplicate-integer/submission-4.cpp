class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> available;
        for(auto&n:nums){
            if(available.count(n)>0) return true;
            available.insert(n);
        }
        return false;
    }
};