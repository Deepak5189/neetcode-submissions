class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        // 
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        auto& vec=mp[key];
        if(timestamp>=vec[vec.size()-1].first) return vec[vec.size()-1].second;
        if(timestamp< vec[0].first) return "";
        int l=0, r=vec.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(vec[mid].first<=timestamp){
                l=mid+1;
            }else r=mid-1;
        }
        return vec[r].second;
    }
};
