#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Greedy approach
// TC: O(NlogN + MlogM + M)
// SC: O(1)
int findContentChildren(vector<int>& g, vector<int>& s) {
    int l = 0, r = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    while(l<s.size() and r<g.size()){
        if(g[r]<=s[l])
            r++;
        l++;
    }
    return r;
}
int main(){
    int gn, sn, ele;
    vector<int> g, s;
    cout<<"Enter number of children: ";
    cin>>gn;
    cout<<"Enter greed factor of each child: ";
    for(int i = 0;i<gn;i++){
        cin>>ele;
        g.push_back(ele);
    }
    cout<<"Enter number of cookies";
    cin>>sn;
    cout<<"Enter cookie sizes: ";
    for(int i = 0;i<sn;i++){
        cin>>ele;
        s.push_back(ele);
    }
    cout<<"No. of children with content is "<<findContentChildren(g, s)<<endl;
}