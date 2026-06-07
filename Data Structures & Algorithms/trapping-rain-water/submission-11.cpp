class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1;
        int res=0, maxl=height[0], maxr=height[height.size()-1];
        while(l<=r){
            if(maxl<maxr){
                maxl=max(maxl, height[l]);
                int water=maxl-height[l];
                if(water>0) res+=water;
                l++;
            }else{
                maxr=max(maxr, height[r]);
                int water=maxr-height[r];
                if(water>0) res+=water;
                r--;
            }
        }
        return res;
    }
};
