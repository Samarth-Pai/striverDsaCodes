#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// TC: O(V + E)
// SC: O(V + E)
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    int from, to, price;
    for(vector<int> v: flights){
        from = v[0], to = v[1], price = v[2];
        adj[from].push_back({to, price});
    }
    vector<int> prices(n, 1e9);
    prices[src] = 0;
    queue<pair<int, int>> pq;
    pq.push({0, src});
    int stops = -1;
    while(!pq.empty()){
        if(stops == k)
            break;
        int n = pq.size();
        for(int i = 0;i<n;i++){
            int price = pq.front().first;
            int node = pq.front().second;
            pq.pop();
            for(auto& [nextNode, nextPrice] : adj[node]){
                if(price + nextPrice < prices[nextNode]){
                    int newPrice = price + nextPrice;
                    prices[nextNode] = newPrice;
                    pq.push({newPrice, nextNode});
                }
            }
        }
        stops++;
    }
    if(prices[dst] == 1e9)
        return -1;
    return prices[dst];
}
int main(){
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };
    cout<<"Cheapest price: "<<findCheapestPrice(4, flights, 0, 3, 1)<<endl;
}