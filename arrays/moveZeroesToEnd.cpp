#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Brute approach
// Time complexity: O(N)
// Space complexity: O(X) where X is the no. of non-zero elements. Worst case: O(N) where there is no zero
// void moveZeroes(vector<int> &arr){
//     int n = arr.size();
//     vector<int>temp;
//     for(int i: arr)
//         if(i)
//             temp.push_back(i);
//     int tempN = temp.size();
//     for(int i=0;i<tempN;i++)
//         arr[i] = temp[i];
//     for(int i=tempN;i<n;i++)
//         arr[i] = 0;
// }

// Optimal approach
// Time complexity: O(N)
// Space complexity: O(1)
void moveZeroes(vector<int> &arr){
    int j=-1,i,n=arr.size();
    for(i=0;i<n;i++)
        if(arr[i]==0){
            j = i;
            break;
        }
    if(j!=-1)
        for(i=j+1;i<n;i++){
            if(arr[i])
                swap(arr[j++],arr[i]);
        }
}
int main(){
    int n, ele;
    vector<int>arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++){
        cin>>ele;
        arr.push_back(ele);
    }
    moveZeroes(arr);
    cout<<"The array after moving all the zeroes to the end: ";
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}