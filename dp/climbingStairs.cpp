#include<iostream>
using namespace std;    
// int f(int n){
//     if(n == 0 or n == 1)
//         return 1;
//     int left = f(n-1);
//     int right = f(n-2);
//     return left + right;
// }
// int climbStairs(int n) {
//     return f(n);
// }

// Fibonacci series
// TC: O(N)
// SC: O(1)
int climbStairs(int n){
    int a = 1, b = 1, c;
    for(int i = 0;i<n-1;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"No. of steps: "<<climbStairs(n)<<endl;
}