#include<iostream>

// Brute approach
// TC: O(N)
// SC: O(1)
// long long int floorSqrt(long long int n) {
//     long long int ans = 0;
//     for(long long i = 1;i<=n;i++){
//         if(i*i<=n){
//             ans = i;
//         }
//         else
//             break;
//     }
//     return ans;
// }

// Better approach: binary search with ans variable
// long long int floorSqrt(long long int n){
//     long long int ans = 0;
//     long long int low = 0, high = n, mid;
//     while(low<=high){
//         mid = (low + high )/2;
//         if(mid*mid<=n){
//             ans = mid;
//             low = mid + 1;
//         }
//         else
//             high = mid - 1;
//     }
//     return ans;
// }

// Optimal solution: binary search which has high as final ans
long long int floorSqrt(long long int n){
    long long int low = 0, high = n, mid;
    while(low<=high){
        mid = (low + high )/2;
        if(mid*mid<=n){
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high;
}

using namespace std;
int main(){
    long long int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Floor of square root of "<<n<<" is "<<floorSqrt(n)<<endl;
}