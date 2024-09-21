#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Time complexity: O(N^2)
// Space complexity: 0(1)
// void leftRotate(vector<int> &arr, int n){
//     int first = arr[0];
//     int i;
//     for(i=1;i<n;i++)
//         arr[i-1] = arr[i];
//     arr[n-1] = first;
// }
// void rightRotate(vector<int> &arr, int n){
//     int last = arr[n-1];
//     for(int j=n-2;j>=0;j--)
//         arr[j+1] = arr[j];
//     arr[0] = last;
// }
// void rotate(vector<int> &arr, int k){
//     int n = arr.size(), last;
//     k%=n;
//     int nBy2 = n/2;
//     if(k>nBy2)
//         for(int i=0;i<n-k;i++)
//             rightRotate(arr, n);
//     else
//         for(int i=0;i<k;i++)
//             leftRotate(arr, n);
// }

// Time complexity: 0(N+D)
// Space complexity: 0(D)
// void rotateArray(vector<int>&arr, int k){
//     vector<int>temp;
//     int n = arr.size();
//     for(int i=0;i<k;i++)
//         temp.push_back(arr[i]);
//     int remaingN = n-k;
//     for(int i=k;i<n;i++)
//         arr[i-k] = arr[i];
//     for(int i=remaingN;i<n;i++)
//         arr[i] = temp[i-remaingN];
// }

// Time complexity: O(2N)
// Space complexity: 0(1)
// void rotateArray(vector<int>&arr, int k){
//     reverse(arr.begin(),arr.begin()+k);
//     reverse(arr.begin()+k,arr.end());
//     reverse(arr.begin(),arr.end());
// }

//For submitting on naukri.com
vector<int> rotateArray(vector<int>arr, int k){
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());
    return arr;
}

// Assignment i.e rotate by right
void rotateR(vector<int>&arr, int k){
    int n = arr.size();
    reverse(arr.begin(),arr.begin()+n-k);
    reverse(arr.begin()+n-k,arr.end());
    reverse(arr.begin(),arr.end());
}
int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int>arr;
    int ele;
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    int k;
    cout<<"Enter the no. of times the array to be rotated: ";
    cin>>k;
    vector<int>rotated = rotateArray(arr, k);
    cout<<"The array after rotating for "<<k<<" times: ";
    for(int i: rotated)
        cout<<i<<" ";
    cout<<endl;
    rotateR(arr, k);
    cout<<"The array after rotating for "<<k<<" times: ";
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}