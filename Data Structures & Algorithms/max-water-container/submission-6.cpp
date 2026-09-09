class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j=heights.size()-1, n=heights.size();
        int maxW=0;
        while(i<j){
            int curW=min(heights[i], heights[j])*(j-i);
            maxW=max(maxW, curW);
            if(heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxW;
    }
};
