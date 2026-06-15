class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res;
        for(int i=0;i<temp.size();i++){
            int warmDays=0;
            for(int j=i+1;j<temp.size();j++){
                if(temp[j]>temp[i]){
                    warmDays=j-i;
                    break;
                }
            }
            res.push_back(warmDays);
        }
    return res;
    }
};
