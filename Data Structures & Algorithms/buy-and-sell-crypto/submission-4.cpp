class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minYet=prices[0], ans=0;
        for(int i=1;i<prices.size();i++){
            ans=max(ans, prices[i]-minYet);
            minYet=min(prices[i], minYet);
        }
        return ans;
    }
};
