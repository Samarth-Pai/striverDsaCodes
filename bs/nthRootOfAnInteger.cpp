#include<iostream>
using namespace std;

int mulNTimes(int n, int m){
    long long ans = 1;
    for(int i =1;i<=n;i++)
        ans*=m;
    return ans;
}

// Brute approach
// TC: O(M log_2N)
// SC: O(1)
// int NthRoot(int n, int m){
//     for(int i = 1;i<=m;i++){
//         int val = mulNTimes(n, i);
//         if(val==m)
//             return i;
//         else if(val>m)
//             break;
//     }
//     return -1;
// }

// return 1 if == m
// return 0 if < m
// return 2 if > m
int mulNTimes(int n, int m, int maxNo){
    long long ans = 1;
    for(int i = 1;i<=n;i++){
        ans*=m;
        if(ans>maxNo)
            return 2;
    }
    if(ans==maxNo)
        return 1;
    return 0;
}

int NthRoot(int n, int m){
    int low = 1, high = m, mid; 
    while(low<=high){
        mid = (low + high)/2;
        int val = mulNTimes(n, mid, m);
        if(val == 1)
            return mid;
        else if(val == 2)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}



int main(){
    int n, m;
    cout<<"Enter a number and its nth root to find: ";
    cin>>m>>n;
    cout<<n<<" th root of "<<m<<" is "<<NthRoot(n, m)<<endl;
}