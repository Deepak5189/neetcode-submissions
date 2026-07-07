class Twitter {
public:
    int time=0;
    unordered_map<int, vector<pair<int, int>>> user_post_map;
    unordered_map<int, unordered_set<int>> user_follower_map;
    Twitter() {
        // 
    }
    
    void postTweet(int userId, int tweetId) {
        user_post_map[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        user_follower_map[userId].insert(userId);
        priority_queue<vector<int>> pq;
        for(auto& u:user_follower_map[userId]){
            
            if(user_post_map[u].empty()){
                continue;
            }

            int idx=user_post_map[u].size()-1;
            pq.push({
                user_post_map[u][idx].first,
                user_post_map[u][idx].second,
                u,
                idx
            });
        }
        vector<int>res;
        while(!pq.empty() && res.size()<10){
            auto cur=pq.top();
            pq.pop();
            res.push_back(cur[1]);

            if(cur[3]>0){
                pq.push({
                    user_post_map[cur[2]][cur[3]-1].first,
                    user_post_map[cur[2]][cur[3]-1].second,
                    cur[2],
                    cur[3]-1
                });
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        user_follower_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user_follower_map[followerId].erase(followeeId);
    }
};
