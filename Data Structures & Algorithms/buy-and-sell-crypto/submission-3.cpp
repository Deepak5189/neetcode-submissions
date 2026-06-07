class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof=INT_MIN;
        int minSoFar=INT_MAX;
        for(int& price:prices){
            int temp=price-minSoFar;
            prof=max(temp, prof);
            minSoFar=min(minSoFar, price);
        }
        if(prof>=0) return prof;
        return 0;
    }
};
