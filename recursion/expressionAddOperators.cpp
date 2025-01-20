#include<iostream>
#include<climits>
#include<vector>
using namespace std;
void helper(vector<string> &res, string num, string curExp, int target, int pos, long long curVal, long long last){
    if(pos == num.size()){
        if(curVal == target) res.push_back(curExp);
        return;
    }
    for(int i = pos;i<num.size();i++){
        if(i!=pos and num[pos]=='0') break;
        string part = num.substr(pos, i - pos + 1);
        long long cur = stoll(part);
        if(cur>INT_MAX or cur<INT_MIN) continue;
        if(pos == 0){
            helper(res, num, part, target, i + 1, cur, cur);
        }
        else{
            helper(res, num, curExp + "+" + part, target, i + 1, curVal + cur, cur);
            helper(res, num, curExp + "-" + part, target, i + 1, curVal - cur, -cur);
            helper(res, num, curExp + "*" + part, target, i + 1, curVal - last + last * cur, last * cur);
        }
    }
}
// TC: O(3^N)
// SC: O(N)
vector<string> addOperators(string num, int target) {
    vector<string> res;
    helper(res, num, "", target, 0, 0, 0);
    return res;
}
int main(){
    string num;
    int target;
    cout<<"Enter number: ";
    cin>>num;
    cout<<"Enter target: ";
    cin>>target;
    vector<string> res = addOperators(num, target);
    cout<<"Valid expressions: ";
    for(string s: res) cout<<s<<" ";
    cout<<endl;
}