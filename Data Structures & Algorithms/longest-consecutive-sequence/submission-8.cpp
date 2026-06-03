class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev=INT_MIN;
        int len=0, maxlen=0;
        for(int i=0;i<nums.size();i++){
            cout<<prev<<" "<<nums[i]<<" "<<len<<" "<<maxlen<<endl;
            if(nums[i]==prev){
                continue;
            }else if(nums[i]==prev+1){
                len++;
                prev=nums[i];
            }else{
                cout<<"else"<<endl;
                maxlen=max(len, maxlen);
                len=1;
                prev=nums[i];
            }
        }
        maxlen=max(len, maxlen);
        return maxlen;
    }
};
