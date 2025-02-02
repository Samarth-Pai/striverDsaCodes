#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
// void findDigits(string num, int k, int ind, int ds, vector<int> &combs){
//     if(ind==num.size()){
//         if(k == 0) combs.push_back(ds);
//         return;
//     }
//     if(k == 0){
//         combs.push_back(ds);
//         return;
//     }
//     int digit = num[ind] - '0';
//     cout<<"Digit is "<<digit<<" with "<<ds<<" and "<<ds*10+digit<<endl;
//     findDigits(num, k-1, ind+1, ds*10+digit, combs);
//     findDigits(num, k, ind+1, ds, combs);
// }

// Brute approach
// TC: O(2^(N-K))
// SC: O(N^2)
// string removeKdigits(string num, int k) {
//     vector<int> combs;
//     int ds = 0;
//     findDigits(num, num.size()-k, 0, ds, combs);
//     return to_string(*min_element(combs.begin(), combs.end()));
// }

// Optimal solution
// TC: O(3N) + O(K)
// SC: O(2N)
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        for(int i = 0;i<n;i++){
            while(!st.empty() and k>0 and st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        while(res.size() and res.back()=='0') res.pop_back();
        if(res.empty()) return "0";
        reverse(res.begin(), res.end());
        return res;
    }
int main(){
    string num;
    int k;
    cout<<"Enter num and k: ";
    cin>>num>>k;
    string res = removeKdigits(num, k);
    cout<<"Smallest number of removed "<<k<<" digits is "<<res<<endl;
}