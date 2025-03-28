#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n+1);
    for(vector<int> v: times){
        adj[v[0]].push_back({v[1], v[2]});
    }
    if(adj[k].empty())
        return -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, k});
    vector<int> dist(n+1, INT_MAX);
    dist[k] = 0;
    int currTime, node, newTime;
    int cnt = 0;
    while(!pq.empty()){
        currTime = pq.top().first;
        node = pq.top().second;
        pq.pop();
        for(auto [nextNode, nextTime]: adj[node]){
            newTime = currTime + nextTime;
            if(newTime < dist[nextNode]){
                dist[nextNode] = newTime;
                pq.push({newTime, nextNode});
            }
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(dist[i] == INT_MAX)
            return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}
int main(){
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };
    int ans = networkDelayTime(times, 4, 2);
    cout<<"Network time delay: "<<ans<<endl;
}