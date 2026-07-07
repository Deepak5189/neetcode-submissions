class Twitter {
public:
    unordered_map<int, unordered_set<int>> user_post_map;
    unordered_map<int, unordered_set<int>> user_follower_map;
    vector<int> posts;
    Twitter() {
        // 
    }
    
    void postTweet(int userId, int tweetId) {
        user_post_map[userId].insert(tweetId);
        posts.push_back(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> users;
        users.insert(userId);
        for(auto u:user_follower_map[userId]) users.insert(u);
        unordered_set<int> relPosts;
        for(int u: users){
            for(int p:user_post_map[u]){
                relPosts.insert(p);
            }
        }
        vector<int>res;
        int i=posts.size()-1;
        while(i>=0){
            if(relPosts.count(posts[i])){
                res.push_back(posts[i]);
            }
            if(res.size()==10) return res; 
            i--;
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
