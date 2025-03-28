// Leetcode POTD: 23/03/2025
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
// 1st attempt: 26 March 2025
// int countPaths(int n, vector<vector<int>>& roads) {
//     vector<vector<pair<long long, int>>> adj(n);
//     const int MOD = 1e9 + 7;
//     for(vector<int> v: roads){
//         adj[v[0]].push_back({v[1], v[2]});
//         adj[v[1]].push_back({v[0], v[2]});
//     }
//     vector<long long> dist(n, LLONG_MAX);
//     vector<int> ways(n);
//     dist[0] = 0;
//     ways[0] = 1;
//     // pair of distance, node
//     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
//     pq.emplace(0, 0);
//     while(!pq.empty()){
//         auto [currDist, node] = pq.top();
//         pq.pop();
//         if(currDist > dist[node])
//             continue;
//         for(const auto &[nextNode, nextDist]: adj[node]){
//             long long newDist = currDist + nextDist;
//             if(newDist < dist[nextNode]){
//                 dist[nextNode] = newDist;
//                 ways[nextNode] = ways[node];
//                 pq.emplace(newDist, nextNode);
//             }
//             else if(newDist == dist[nextNode])
//                 ways[nextNode] = (ways[nextNode] + ways[node])%MOD;
//         }
//     }
//     return ways[n-1];
// }

// 2nd attempt: 28 March 2025
int countPaths(int n, vector<vector<int>>& roads) {
    const int MOD = 1000000007;
    vector<vector<pair<long long, int>>> adj(n);
    for(vector<int> v: roads){
        adj[v[0]].push_back({v[1], v[2]});
        adj[v[1]].push_back({v[0], v[2]});
    }
    vector<long long> dist(n, LLONG_MAX);
    vector<int> pathCount(n, 0); 
    pathCount[0] = 1; 
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [currDist, node] = pq.top();
        pq.pop();
        if(currDist > dist[node])
            continue;
        for(auto[nextNode, nextDist]: adj[node]){
            long long newDist = currDist + nextDist;
            if(newDist < dist[nextNode]){
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
                pathCount[nextNode] = pathCount[node];
            }
            else if(newDist == dist[nextNode]){
                pathCount[nextNode] = (pathCount[node] + pathCount[nextNode])%MOD;
            }
        }
    }
    return pathCount[n-1];
}
int main(){
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };
    cout<<"No. of ways to reach the destination: "<<countPaths(7, roads)<<endl;
}