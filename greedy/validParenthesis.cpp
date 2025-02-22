#include<iostream>
#include<vector>
using namespace std;
// Brute approach: backtracking
// TC: O(3^N)
// SC: O(N)
// bool backtrack(string s, int ind, int count){
//     if(count<0)
//         return false;
//     if(ind == s.length()){
//         return count == 0;
//     }
//     if(s[ind] == '*'){
//         return backtrack(s, ind+1, count-1)
//         or backtrack(s, ind+1, count)
//         or backtrack(s, ind+1, count+1);
//     }
//     else if(s[ind] == '(')
//         return backtrack(s, ind+1, count+1);
//     else
//         return backtrack(s, ind+1, count-1);
// }
// bool checkValidString(string s) {
//     string ds;
//     return backtrack(s, 0, 0);
// }

// Better approach: dp
// TC: O(N^2)
// SC: O(N^2)

// Optimal solution: greedy
// TC: O(N)
// SC: O(0)
bool checkValidString(string s) {
    int mini = 0, maxi = 0;
    for(char c: s){
        if(c == '('){
            mini++;
            maxi++;
        }
        else if(c == ')'){
            mini--;
            maxi--;
        }
        else{
            mini--;
            maxi++;
        }
        if(mini<0) mini = 0;
        if(maxi<0) return false;
    }
    return mini<=0 and 0<=maxi;
}
int main(){
    string s;
    cout<<"Enter a string with parenthesis and asterisks: ";
    cin>>s;
    if(checkValidString(s))
        cout<<"Valid parenthesis"<<endl;
    else
        cout<<"Invalid parenthesis"<<endl;
}