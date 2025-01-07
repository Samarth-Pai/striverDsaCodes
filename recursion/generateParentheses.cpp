#include<iostream>
#include<vector>
using namespace std;
void generate(vector<string> &a, int open, int close, string s, int n){
    if(open==n and close==n){
        a.push_back(s);
        return;
    }
    if(open<n)
        generate(a, open+1, close, s+"(", n);
    if(close<open)
        generate(a, open, close+1, s+")", n);
}

// TC: O(2^n)
// SC: O(n)
vector<string> generateParenthesis(int n) {
    vector<string> a;
    generate(a, 0, 0, "", n);
    return a;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    vector<string> ans = generateParenthesis(n);
    for(string s: ans)
        cout<<s<<" ";
    cout<<endl;
}