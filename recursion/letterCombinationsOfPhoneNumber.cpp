#include<iostream>
#include<vector>
using namespace std;
void findCombo(int ind, vector<string> &combos, int n, string &ds, vector<string> &res){
    if(ind==n){
        res.push_back(ds);
        return;
    }
    for(char c: combos[ind]){
        ds.push_back(c);
        findCombo(ind+1, combos, n, ds, res);
        ds.pop_back();
    }
}
vector<string> getKeys(string digits){
    vector<string> ans;
    for(char c: digits){
        if(c=='2') ans.push_back("abc");
        else if(c=='3') ans.push_back("def");
        else if(c=='4') ans.push_back("ghi");
        else if(c=='5') ans.push_back("jkl");
        else if(c=='6') ans.push_back("mno");
        else if(c=='7') ans.push_back("pqrs");
        else if(c=='8') ans.push_back("tuv");
        else ans.push_back("wxyz");
    }
    return ans;
}
// TC: O(4^N)
// SC: O(N)
vector<string> letterCombinations(string digits) {
    if(digits=="") return {};
    int n = digits.size();
    vector<string> combos = getKeys(digits);
    vector<string> res;
    string ds;
    findCombo(0, combos, n, ds, res);
    return res;
}
int main(){
    string s;
    cout<<"Enter a number of digits 2-9: ";
    cin>>s;

    vector<string> ans = letterCombinations(s);
    cout<<"Combinations: ";
    for(string c: ans) cout<<c<<" ";
    cout<<endl;
}