#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> in(numCourses);
    for(vector<int> i: prerequisites){
        adj[i[1]].push_back(i[0]);
        in[i[0]]++;
    }
    queue<int> q;
    for(int i = 0;i<numCourses;i++){
        if(in[i] == 0)
            q.push(i);
    }
    vector<int> res;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(int i: adj[node]){
            in[i]--;
            if(in[i] == 0)
                q.push(i);
        }
    }
    if(res.size() != numCourses)
        return {};
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