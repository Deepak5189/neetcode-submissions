class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto&t:tasks) mp[t]++;

        priority_queue<int> pq;
        for(auto&m:mp) pq.push(m.second);
        queue<pair<int, int>> cool;

        int cycle=0;
        while(!pq.empty() || !cool.empty()){
            if(!pq.empty()){
                int cnt=pq.top();
                pq.pop();
                cnt--;
                if(cnt>0) cool.push({cnt, cycle+n});
            }

            if(!cool.empty() && cool.front().second==cycle){
                pq.push(cool.front().first);
                cool.pop();
            }
            cycle++;
        }
        return cycle;
    }
};
