#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> in(numCourses);
    for(vector<int>p: prerequisites){
        in[p[0]]++;
        adj[p[1]].push_back(p[0]);
    }
    vector<int> res;
    queue<int> q;
    for(int node = 0;node<numCourses;node++){
        if(in[node] == 0)
            q.push(node);
    }
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        res.push_back(ele);
        for(int i: adj[ele]){
            in[i]--;
            if(in[i] == 0)
                q.push(i);
        }
    }
    return res;
}
int main(){
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0}, {2, 0}, {3, 1}, {3, 2}
    };
    vector<int> order = findOrder(numCourses, prerequisites);
    cout<<"Order: ";
    for(int i: order)
        cout<<i<<' ';
    cout<<endl;
}