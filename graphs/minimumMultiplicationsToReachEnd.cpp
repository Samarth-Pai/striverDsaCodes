#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MOD = 100000;
// Brute approach
// int minimumMultiplications(vector<int>& arr, int start, int end) {
//     queue<int> q;
//     q.push(start);
//     int steps = 0;
//     while(!q.empty()){
//         int n = q.size(), newNum, currNum;
//         for(int i = 0;i<n;i++){
//             currNum = q.front();
//             q.pop();
//             if(currNum == end)
//                 return steps;
//             for(int nextNum: arr){
//                 newNum = (nextNum * currNum)%MOD;
//                 q.push(newNum);
//             }
//         }
//         steps++;
//     }
//     return steps;
// }

// Optimal
int minimumMultiplications(vector<int>& arr, int start, int end) {
    if(start == end)
        return 0;
    queue<int> q;
    vector<bool> vis(MOD);
    vis[start] = true;
    q.push(start);
    int steps = 0;
    while(!q.empty()){
        int n = q.size(), newNum, currNum;
        for(int i = 0;i<n;i++){
            currNum = q.front();
            q.pop();
            if(currNum == end)
                return steps;
            for(int nextNum: arr){
                newNum = (nextNum * currNum)%MOD;
                if(vis[newNum])
                    continue;
                vis[newNum] = true;
                q.push(newNum);
            }
        }
        steps++;
    }
    return -1;
}
int main(){
    int n, start, end;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter start and end: ";
    cin>>start>>end;
    cout<<"Minimum multiplications required: ";
    cout<<minimumMultiplications(arr, start, end)<<endl;
}