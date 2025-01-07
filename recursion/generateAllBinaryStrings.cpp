#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void generateBinary(vector<string> &a, int k, char *s, int n){
    if(n==k){
        s[n] = '\0';
        a.push_back(s);
        return;
    }
    if(s[n-1]=='1'){
        s[n] = '0';
        generateBinary(a, k, s, n+1);
    }
    if(s[n-1]=='0'){
        s[n] = '1';
        generateBinary(a, k, s, n+1);
        s[n] = '0';
        generateBinary(a, k, s, n+1);
    }
}
// TC: O(2^k)
// SC: O(k)
vector<string> generateBinaryStrings(int k){
    vector<string> a;
    char s[k+1];
    s[0] = '0';
    generateBinary(a, k, s, 1);
    s[0] = '1';
    generateBinary(a, k, s, 1);
    sort(a.begin(), a.end());
    return a;
}
int main(){
    int k;
    cout<<"Enter k: ";
    cin>>k;
    cout<<"All binary strings without consequitive 1s are: ";
    vector<string> ans = generateBinaryStrings(k);
    for(string i: ans)
        cout<<i<<" ";
    cout<<endl;
}