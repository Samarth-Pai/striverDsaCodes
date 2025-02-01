#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
// Optimal solution
// TC: O(N)
// SC: O(N)
vector<int> asteroidCollision(vector<int>& a) {
    int n = a.size();
    vector<int> st;
    for(int i = 0;i<n;i++){
        if(a[i]>0) st.push_back(a[i]);
        else{
            while(!st.empty() and st.back()>0 and st.back()<abs(a[i])) st.pop_back();
            if(!st.empty() and st.back() == abs(a[i])) st.pop_back();
            else if(st.empty() or st.back()<0) st.push_back(a[i]);
        }
    }
    return st;
}
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter no. of asteroids: ";
    cin>>n;
    cout<<"Enter weights of each asteroids: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    vector<int> res = asteroidCollision(arr);
    cout<<"Asteroids after the collisions: ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}