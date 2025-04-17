#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Not a DP, questiob, still it's a part of DP series

// Approach: Geedy
// TC: O(MlogM + NlogN + min(M, N))
// SC: O(1)
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(s.begin(), s.end());
    sort(g.begin(), g.end());
    int i = 0, j = 0, m = g.size(), n = s.size();
    while(j < n and i < m){
        if(s[j] >= g[i])
            i++;
        j++;
    }
    return i;
}
int main(){
    int m, n;
    cout<<"Enter no. of children: ";
    cin >> m;
    vector<int> g(m);
    cout<<"Enter greed factor of each child: ";
    for(int i = 0;i<m;i++)  
        cin >> g[i];
    cout<<"Enter no. of cookies: ";
    cin >> n;
    vector<int> s(n);
    cout<<"Enter cookie sizes: ";
    for(int i = 0;i<n;i++)
        cin >> s[i];
    cout<<"Enter no. of satisisfied: "<<findContentChildren(g, s)<<endl;
}