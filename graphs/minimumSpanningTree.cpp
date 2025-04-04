#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
// Requirements for MST
// Required data structures
// 1. Min heap
// 2. Visited array
// 3. Mst list that will store all the edges that are a part of MST

// Datatypes of our data structures
// Visited array => int
// Mst list =>  (weight , node name , node parent)



// Steps
// 1. Mark the visited array as 0 for all the nodes

// 2. Start with 0th node and push
// (0,0,-1)
// explanation:  -1 means 0 is the genesis node
// Mark 0 as visited

// 3. Push all the neighbours of 0 in pq Do not mark them visited  (footnote 1)
// Since its a min heap the edge with minimum weight will be at the top

// 4. Pick up the top edge , insert it in the mst , mark the picked node as visited , insert all neighbours of picked node into pq

// 5. keep repeating steps 3 and 4 untill all the nodes have been picked up and thats when the algorithm ends


// footnote:
// 1. why to not mark it visited?
// in bfs , when we push the element inside a queue we mark it as visited cause that element will be picked up later for sure (algorithm ends only when the queue is empty )
// but in msts case even if we push the edge into pq , theres no surety that the edge will be picked up . when prims algo ends there are still a few non accepted edges present in the pq hence we only mark it visited once its picked up from pq

// Prim's algorithm
// TC: O(E + 2ElogE)
// SC: O(E)
/*
int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<bool> vis(V);
    // {dist, {node, parent}}
    // We dont have to find parent so for this problem the pair will be
    // {dist, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});
    int sum = 0;
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(vis[node])
            continue;
        vis[node] = true;
        sum += dist;
        for(vector<int> neighbour: adj[node]){
            int nextNode = neighbour[0];
            int nextDist = neighbour[1];
            if(!vis[nextNode])
                pq.push({nextDist, nextNode});
        }
    }
    return sum;
}
*/

class DSU{
    vector<int> rank, parent;
    public:
    DSU(int n){
        rank.resize(n, 0);
        parent.resize(n, 0);
        for(int i = 0;i<n;i++)
            parent[i] = i;
    }

    void unionByRank(int u, int v){
        int ultPu = findUPar(u);
        int ultPv = findUPar(v);
        if(ultPu == ultPv)
            return;
        else if(rank[ultPu] < rank[ultPv]){
            parent[ultPu] = ultPv;
        }
        else if(rank[ultPv] > rank[ultPu]){
            parent[ultPv] = ultPu;
        }
        else{
            parent[ultPu] = ultPv;
            rank[ultPv]++;
        }
    }

    int findUPar(int u){
        if(parent[u] == u)
            return u;
        return parent[u] = findUPar(parent[u]);
    }
};

// Kruskal's algorithm
int spanningTree(int n, vector<vector<int>> adj[]) {
    // O(N + E)
    vector<pair<int, pair<int, int>>> edges;
    for(int u = 0;u<n;u++){
        for(vector<int> edge: adj[u]){
            int v = edge[0];
            int wt = edge[1];
            edges.push_back({wt, {u, v}});
        }
    }
    // O(M log M)
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int maxwt = 0;
    // O(M * 4 alpha * 2)
    for(auto p: edges){
        int wt = p.first;
        int u = p.second.first;
        int v = p.second.second;
        if(dsu.findUPar(u) != dsu.findUPar(v)){
            maxwt += wt;
            dsu.unionByRank(u, v);
        }
    }
    return maxwt;
} 
int main(){
    vector<vector<int>> adj[] = {
        {{1, 5}, {2, 1}},
        {{0, 5}, {2, 3}},
        {{0, 1}, {1, 3}}
    };
    cout<<"Sum of MST: "<<spanningTree(3, adj)<<endl;
}