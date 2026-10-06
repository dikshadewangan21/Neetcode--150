class Twitter {
private:
    // userId -> set of users they follow
    unordered_map<int, unordered_set<int>> following;

    // userId -> {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    int time = 0;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        // Max heap:
        // {time, tweetId, userId, index}
        priority_queue<
            tuple<int, int, int, int>
        > pq;

        // Add user's own tweets
        if (!tweets[userId].empty()) {
            int i = tweets[userId].size() - 1;
            auto [t, id] = tweets[userId][i];
            pq.push({t, id, userId, i});
        }

        // Add tweets of followed users
        for (int followee : following[userId]) {
            if (!tweets[followee].empty()) {
                int i = tweets[followee].size() - 1;
                auto [t, id] = tweets[followee][i];
                pq.push({t, id, followee, i});
            }
        }

        // Get 10 most recent tweets
        while (!pq.empty() && result.size() < 10) {
            auto [t, tweetId, user, index] = pq.top();
            pq.pop();

            result.push_back(tweetId);

            // Add the next older tweet from same user
            if (index > 0) {
                int newIndex = index - 1;
                auto [newTime, newTweetId] = tweets[user][newIndex];

                pq.push({
                    newTime,
                    newTweetId,
                    user,
                    newIndex
                });
            }
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};