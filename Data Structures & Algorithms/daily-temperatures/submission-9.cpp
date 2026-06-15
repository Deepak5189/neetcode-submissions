class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<stack<int>> trk(101);
        for(int i=temp.size()-1;i>=0;i--){
            trk[temp[i]].push(i);
        }

        vector<int> res;
        for(int j=0;j<temp.size();j++){
            int minDist=INT_MAX;
            for(int i=temp[j]+1;i<101;i++){
                if(!trk[i].empty()){
                    minDist=min(minDist, trk[i].top()-j);
                }
            }
            if(minDist==INT_MAX) res.push_back(0);
            else res.push_back(minDist);
            trk[temp[j]].pop();
        }
        return res;
    }
};
