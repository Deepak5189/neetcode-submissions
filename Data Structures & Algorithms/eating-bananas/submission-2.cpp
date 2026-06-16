class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=INT_MIN;
        for(auto&b:piles) r=max(b, r);

        while(l<=r){
            int mid=l+(r-l)/2;
            int ht=0;
            for(auto&b:piles){
                ht+=b/mid;
                if(b%mid) ht++;
            }
            if(ht<=h) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
