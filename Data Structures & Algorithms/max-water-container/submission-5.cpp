class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxa=0;
        int i=0, j=heights.size()-1;
        while(i<j){
            int cura=(j-i)*min(heights[i], heights[j]);
            maxa=max(cura, maxa);
            if(heights[i]<heights[j]) i++;
            else j--;
        }
        return maxa;
    }
};
