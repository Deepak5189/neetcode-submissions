class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                maxProf=max(prices[j]-prices[i], maxProf);
            }
        }
        return maxProf;
    }
};
