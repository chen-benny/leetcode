// hash-map + min-heap, T: O(nlogk) getNewsFeed, S: O(n)

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Twitter {
private:
    int timestamp = 0;
    static constexpr int FEED_SIZE = 10;

    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets; // userId -> {timestamp, tweetId}
    std::unordered_map<int ,std::unordered_set<int>> following; // userId -> set of followed userIds 

public:
    Twitter() = default;

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    std::vector<int> getNewsFeed(int userId) {
        using T = std::tuple<int, int, int, int>; // timestamp, tweetId, userId, idx
        std::priority_queue<T, std::vector<T>> maxHeap;

        auto seed = [&](int uid) {
            auto it = tweets.find(uid);
            if (it == tweets.end() || it->second.empty()) { return; }
            int idx = static_cast<int>(it->second.size()) - 1;
            auto&[ts, tid] = it->second[idx];
            maxHeap.push({ts, tid, uid, idx});
        };

        seed(userId);
        if (following.count(userId)) {
            for (int uid : following[userId]) { seed(uid); }
        }

        std::vector<int> feed;
        feed.reserve(FEED_SIZE);

        while (!maxHeap.empty() && static_cast<int>(feed.size()) < FEED_SIZE) {
            auto [ts, tid, uid, idx] = maxHeap.top(); maxHeap.pop();
            feed.push_back(tid);
            if (idx > 0) {
                auto& [pts, ptid] = tweets[uid][idx - 1];
                maxHeap.push({pts, ptid, uid, idx - 1});
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

// global timestamp
// max-heap for most recent
// seed with latest tweet per user
// unordered_set for following O(1) follow/unfollow/lookup
// cache behavior
// one user follows millions of users
