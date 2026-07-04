class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> min_heap;
        for(auto& p:points){
            min_heap.push({(p[0]*p[0]) + (p[1]*p[1]), p});
            if(min_heap.size()>k) min_heap.pop();
        }
        vector<vector<int>> res;
        while(!min_heap.empty()){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return res;
    }
};
