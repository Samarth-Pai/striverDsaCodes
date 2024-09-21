#include<iostream>
#include<vector>
using namespace std;
// Brute force approach
// Time complexity: O(N^2)
// Space complexity: O(1)
// int missingNumber(vector<int>a, int N) {
//     int i, j, flag;
//     for(i=1;i<N;i++){
//         flag = 0;
//         for(j=0;j<N-1;j++){
//             if(a[j]==i){
//                 flag = 1;
//                 break;
//             }
//         }
//         if(flag==0)
//             return i;
//     }
//     return N;
// }

// Better approach: hashing
// Time complexity: O(N) + O(N)
// Space complexity: O(N)
// int missingNumber(vector<int>a, int N){
//     vector<bool>hashArr(N);
//     for(int i: a)
//         hashArr[i-1] = true;
//     for(int i=0;i<N-1;i++)
//         if(hashArr[i]==false)
//             return i+1;
//     return N;
// }

// Optimal solution 1: sum
// TC: O(N)
// SC: O(1)
// int missingNumber(vector<int>a, int N){
//     int sum = N*(N+1)/2, sumOfArray = 0;
//     for(int i: a)
//         sumOfArray+=i;
//     return sum-sumOfArray;
// }

// Optimal solution 2: xor; better than sum as the sum has to store a large number i.e N*(N+1)/2
// TC: O(N)
// SC: O(1)
int missingNumber(vector<int>a, int N){
    int xor1 = 0, xor2 = 0;
    for(int i=0;i<N-1;i++){
        xor2^=a[i];
        xor1^=i+1;
    }
    xor1^=N;
    return xor1^xor2;
}
int main(){
    int n, ele;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    int wanted = missingNumber(arr, n+1);
    cout<<"Missing number is "<<wanted<<endl;
}