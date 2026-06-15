class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> p;
        unordered_set<double> t;
        for(int i=0;i<position.size();i++){
            int pos=position[i];
            double  time=(double)(target-position[i])/speed[i];
            p.push_back({pos, time});
        }
        sort(p.rbegin(), p.rend());
        int fleets=0;
        for(int i=0;i<p.size();i++){
            if(i>=1 && p[i].second<=p[i-1].second){
                p[i].second=p[i-1].second;
            }
            t.insert(p[i].second);
        }
        return t.size();
    }
};
