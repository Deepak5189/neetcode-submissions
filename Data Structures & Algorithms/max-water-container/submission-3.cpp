class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxw=0;
        for(int i=0;i<heights.size();i++){
            for(int j=i+1;j<heights.size();j++){
                int curw=(j-i)*min(heights[i], heights[j]);
                maxw=max(curw, maxw);
            }
        }
        return maxw;
    }
};
