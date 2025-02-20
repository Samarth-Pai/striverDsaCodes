#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<int, vector<int>, greater<int>> sums;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    for(int i: A){
        for(int j: B){
            int sum = i + j;
            if(sums.size() < C){
                sums.push(sum);
            }
            else if(sums.top() < sum){
                sums.pop();
                sums.push(i + j);
            }
            else
                break;  
        }
    }
    vector<int> res;
    for(int i = 0;i<C;i++){
        res.push_back(sums.top());
        sums.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n, ele;
    vector<int> A, B;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array A elements: ";
    for(int i  = 0 ;i<n;i++){
        cin>>ele;
        A.push_back(ele);
    }

    cout<<"Enter array B elements: ";
    for(int i  = 0;i<n;i++){
        cin>>ele;
        B.push_back(ele);
    }

    vector<int> maxSums = solve(A, B, n);
    cout<<"Maximum sum combinations: ";
    for(int i: maxSums)
        cout<<i<<" ";
    cout<<endl;
}