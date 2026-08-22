class Twitter {
public:
                                 //time slot
    unordered_map<int,vector<pair<int,int>>>ut_map; //user -> aur uke tweets

    unordered_map<int,unordered_set<int>>uf_map; //user ->follows these
    int cnt=1;
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        ut_map[userId].push_back({cnt,tweetId});
        cnt++;
         if (ut_map[userId].size() > 10) {
            ut_map[userId].erase(ut_map[userId].begin());
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>maxheap;
        //user ke dalo tweets
        for(auto it:ut_map[userId]){
            maxheap.push(it);
        }
        
        //baki following ke tweets
        for(auto users:uf_map[userId]){
            for(auto it:ut_map[users]){
                maxheap.push(it);
            }
        }

        vector<int>ans;
        while(!maxheap.empty()){
            if(ans.size()>=10) return ans;
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        uf_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        uf_map[followerId].erase(followeeId);
    }
};
