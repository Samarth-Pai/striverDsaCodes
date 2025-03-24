#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> in(numCourses);
    for(vector<int> i: prerequisites){
        adj[i[1]].push_back(i[0]);
        in[i[0]]++;
    }
    queue<int> q;
    for(int i = 0;i<numCourses;i++)
        if(in[i] == 0)
            q.push(i);
    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(int i: adj[node]){
            in[i]--;
            if(in[i] == 0)
                q.push(i);
        }
    }
    return cnt == numCourses;
}
int main(){
    int numCourses = 2;
    vector<vector<int>> prer = {
        {1, 0}
    };
    cout<<"Can finish all courses? "<<canFinish(numCourses, prer)<<endl;
}