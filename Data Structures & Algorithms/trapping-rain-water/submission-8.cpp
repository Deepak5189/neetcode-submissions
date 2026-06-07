class Solution {
public:
    int trap(vector<int>& heights) {
        vector<int> leftmax(heights.size(), 0);
        vector<int> rightmax(heights.size(), 0);
        for(int i=1;i<heights.size();i++){
            leftmax[i]=max(leftmax[i-1], heights[i-1]);
        }
        for(int i=heights.size()-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1], heights[i+1]);
        }
        int res=0;
        for(int i=0;i<heights.size();i++){
            int water=min(leftmax[i], rightmax[i]) - heights[i];
            if(water>0) res+=water;
        }
        return res;
    }
};
