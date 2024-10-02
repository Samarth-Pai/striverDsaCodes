#include<iostream>
#include<vector>
using namespace std;

// Brute approach
// TC: O(N^2)
// SC: O(1)
// vector<int> findTwoElement(vector<int> arr) {
//     int ct, missing = -1, repeating = -1, n = arr.size();
//     for(int i = 1;i<=n;i++){
//         ct = 0;
//         for(int j = 0;j<n;j++){
//             if(arr[j] == i)
//                 ct++;
//         }
//         if(ct==2) repeating = i;
//         else if(ct==0) missing = i;
//         if(repeating!=-1 and missing!=-1) break;
//     }
//     return {repeating, missing};
// }

// Better approach: hashing
// TC: O(2N)
// SC: O(N)
// vector<int> findTwoElement(vector<int> arr){
//     int n = arr.size();
//     int hasharr[n+1] = {};
//     for(int i = 0;i<n;i++)
//         hasharr[arr[i]]++;
//     int missing = -1, repeating = -1;
//     for(int i = 1;i<=n;i++){
//         if(hasharr[i]==2)  repeating = i;
//         else if(hasharr[i]==0) missing = i;
//         if(missing!=-1 and repeating!=-1) break;
//     }
//     return {repeating, missing};
// }
// Optimal solution 1: maths
// TC: O(N)
// SC: O(1)
// vector<int> findTwoElement(vector<int> arr){
//     long long N = arr.size();
//     long long n = N;
//     long long SN = n*(n+1)/2;
//     long long S2N = n*(n+1)*(2*n+1)/6;
//     long S = 0, S2 = 0;
//     for(int i = 0;i<n;i++){
//         S+=arr[i];
//         S2+=(long long)arr[i] * (long long)arr[i];
//     }
//     long long val1 = S - SN; // x - y
//     if(val1==0) return {0, 0};
//     long long val2 = S2 - S2N; // x^2 - y^2 = (x - y)(x + y)
//     val2 = val2 / val1; // x + y
//     long long x = (val1 + val2) / 2; // repeating
//     long long y = x - val1; // missing
//     return {(int)x, (int)y};
// }

// Optimal solution: XOR
// TC: O(N)
// SC: O(1)
vector<int> findTwoElement(vector<int> arr){
    int n = arr.size();
    int xr = 0;

    // Find xor of all number
    for(int i = 0;i<n;i++){
        xr = xr ^ arr[i];
        xr = xr ^ (i+1);
    }
    
    // Find differentiating bit
    int bitNo = xr & ~(xr-1);

    // Grouping
    int zero = 0;
    int one = 0;
    for(int i = 1;i<=n;i++){
        if((i & bitNo) != 0)
            one^=i;
        else
            zero^=i;
    }

    // Identify the numbers
    int cnt = 0;
    for(int i = 0;i<n;i++)
        if(arr[i]==zero)
            cnt++;
    if(cnt==2)
        return {zero, one};
    return {one, zero};
}

int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the array elements with a missing and a repeating number from 1 to "<<n<<" : ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    vector<int>missingRepeating = findTwoElement(arr);
    cout<<"Repeating number: "<<missingRepeating[0]<<endl;
    cout<<"Missing number: "<<missingRepeating[1]<<endl;
}