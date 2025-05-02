#include<iostream>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(N)
// int repeatedStringMatch(string a, string b) {
//     if(a.find(b) < a.size())
//         return 1;
//     int res = 1;
//     string s = a;
//     while(s.size() <= a.size() + b.size()){
//         s.append(a);
//         res++;
//         if(s.find(b) < s.size())
//             return res;
//     }
//     return -1;
// }

const int MOD = 1e6;
// Used to find the index of target in source
int rabinKarp(string source, string target){
    cout<<source<<' '<<target<<endl;
    int S = source.size();
    int T = target.size(), p = 1, k = 31;
    for(int i = 0;i<T-1;i++)
        p = (p * k)%MOD;
    
    int targetHash = 0;
    for(int i = 0;i<T;i++){
        targetHash = (targetHash*k + target[i])%MOD;
    }

    int sourceHash = 0;
    for(int i = 0;i<S;i++){
        sourceHash = (sourceHash*k + source[i])%MOD;
        if(i<T-1)
            continue;
        if(sourceHash == targetHash and source.substr(i-T+1, T) == target)
            return i - T + 1;
        sourceHash = (sourceHash - p * source[i-T+1]%MOD + MOD)%MOD;
    }
    return -1;
}


// Optimal solution: Rabit Karp hashing algorithm
// TC: O(N + M)
// SC: O(N)
int repeatedStringMatch(string a, string b) {
    string source = a;
    int cnt = 1;
    while(source.size() < b.size()){
        source.append(a);
        cnt++;
    }

    if(source == b)
        return cnt;
    else if(rabinKarp(source, b) != -1)
        return cnt;
    else if(rabinKarp(source + a, b) != -1)
        return cnt + 1;
    return -1;
}

int main(){
    string a, b;
    cout<<"Enter two string: ";
    cin>>a>>b;
    cout<<"No. of repeats: "<<repeatedStringMatch(a, b)<<endl;
}