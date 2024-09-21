#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Brute approach
// TC: O(N^2)
// SC: O(N) to store the answer
// vector<int> leaders(int n, int a[]) {
//     vector<int>leaderss;
//     for(int i = 0;i<n;i++){
//         int lead = a[i];
//         bool isLeader = true;
//         for(int j = i+1;j<n;j++){
//             if(a[j]>lead){
//                 isLeader = false;
//                 break;
//             }
//         }
//         if(isLeader) leaderss.push_back(lead);
//     }
//     return leaderss;
// }

// Optimal solution
// TC: O(N)
// SC: O(N) to store the output
vector<int> leaders(int n, int a[]){
    int max = a[n-1];
    vector<int>leaderss;
    for(int i =n-1;i>=0;i--){
        if(a[i]>=max){
            leaderss.insert(leaderss.begin(), a[i]);
            max = a[i];
        }
    } 
    return leaderss;
}

int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>leads = leaders(n, arr);
    cout<<"Leaders: ";
    for(int i: leads) cout<<i<<" ";
    cout<<endl;
}