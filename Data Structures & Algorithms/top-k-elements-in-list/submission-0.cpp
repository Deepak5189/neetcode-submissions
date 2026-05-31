class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto& num:nums){
            freq[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto&val:freq){
            pq.push({val.second, val.first});
        }
        vector<int>res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
