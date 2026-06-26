class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0], fast=nums[0];
        slow=nums[slow], fast=nums[nums[fast]];

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        int temp=nums[0];
        while(slow!=temp){
            slow=nums[slow];
            temp=nums[temp];
        }

        return slow; 
    }
};
