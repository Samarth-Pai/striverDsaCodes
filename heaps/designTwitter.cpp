#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

struct user{
    set<int> following;
    vector<pair<int, int>> tweets;
};

class Twitter {
public:
    int tweetNo = 0;
    map<int, user> users;
    
    void postTweet(int userId, int tweetId) {
        users[userId].tweets.push_back({++tweetNo, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        if(users.find(userId) == users.end())
            return {};
        vector<int> feed;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for(pair<int, int> p: users[userId].tweets)
            pq.push({p.first, p.second});
        for(int followeeId: users[userId].following){
            user u = users[followeeId];
            for(pair<int, int> p: u.tweets){
                pq.push({p.first, p.second});
            }
        }
        int limit = 10;
        while(limit-- and !pq.empty()){
            feed.push_back(pq.top().second);
            pq.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        users[followerId].following.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId
        or users.find(followerId) == users.end())
            return;
        users[followerId].following.erase(followeeId);
    }
};
int main(){
    Twitter twitter = Twitter();
    /*
    twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
    vector<int> res = twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
    for(int i: res) cout<<i<<" ";
    cout<<endl;
    twitter.follow(1, 2);    // User 1 follows user 2.
    twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
    res = twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    for(int i: res) cout<<i<<" ";
    cout<<endl;
    twitter.unfollow(1, 2);  // User 1 unfollows user 2.
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
    */
   /*
    twitter.postTweet(1, 1);
    vector<int> res = twitter.getNewsFeed(1);
    for(int i: res) cout<<i<<" ";
    cout<<endl;
    twitter.follow(2, 1);
    res = twitter.getNewsFeed(2);
    for(int i: res) cout<<i<<" ";
    cout<<endl;
    twitter.unfollow(2, 1);
    res = twitter.getNewsFeed(2);
    for(int i: res) cout<<i<<" ";
    cout<<endl;
    */
    vector<int> posts = {5, 3, 101, 13, 10, 2, 94, 505, 333, 22, 11};
    for(int post: posts)
        twitter.postTweet(1, post);
    posts = twitter.getNewsFeed(1);
    for(int post: posts)
        cout<<post<<" ";
    cout<<endl;
}