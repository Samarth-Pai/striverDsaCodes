#include<iostream>
#include<vector>
#include<set>
using namespace std;

// Brute approach
// Time complexity: O(NlogN + N)
// Space complexity: O(N)
// int removeDuplicates(vector<int> &arr, int n){
//     set<int>uniqueElements;
//     for(int i=0;i<n;i++)
//         uniqueElements.insert(arr[i]);
//     int count=0;
//     for(int i: uniqueElements)
//         arr[count++] = i;
//     return count;
// }

// Two pointer apporach
// Time complexity: O(N)
// Space complexity: O(1)
// My name is Samarth Pai and I am a student of Nitte Mahalinga Adhyantaya Memorial Institute Of Technology, Nitte
int removeDuplicates(vector<int> &arr, int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i])
            arr[++i] = arr[j];
    }
    return i + 1;
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> arr;
    int ele;
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    int nu = removeDuplicates(arr, n);
    cout<<"No of unique elements in the array: "<<nu<<endl;
    cout<<"Unique elements: ";
    for(int i=0;i<nu;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}