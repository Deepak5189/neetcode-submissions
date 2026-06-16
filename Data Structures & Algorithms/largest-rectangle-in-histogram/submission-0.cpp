class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        for(int i=0;i<heights.size();i++){
            int minh=heights[i];
            for(int j=i; j<heights.size();j++){
                minh=min(minh, heights[j]);
                res=max(res, minh*(j-i+1));
            }
        }
        return res;
    }
};