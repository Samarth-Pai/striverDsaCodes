#include<iostream>
#include<vector>
#include<set>
using namespace std;
// Brute force approach
// Time complexity: O(n1logn + n2logn) + O(n1 + n2)
// Space complexity: O(n1 + n2) + O(n1 + n2 )
// vector < int > sortedArray(vector < int > a, vector < int > b) {
//     set<int>arr;
//     for(int i: a)
//         arr.insert(i);
//     for(int i: b)
//         arr.insert(i);
//     vector<int>sortedArr(arr.begin(),arr.end());
//     return sortedArr;
// }

// Optimal solution: two pointer apporoach
// Time complexity: 0(n1 + n2)
// Space complexity: O(n1 + n2), tell to interviewer that we are using this to return the answer, not inlcuded in algorithm.
// Worst case of space complexity is when all the elements from both the arrays are different
vector < int > sortedArray(vector < int > a, vector < int > b) {
    int n1 = a.size(), n2 = b.size(), i=0, j=0;
    vector<int>unionArr;
    while(i<n1 and j<n2){
        if(a[i]<=b[j]){
            if(unionArr.size()==0 or unionArr.back()!=a[i])
                unionArr.push_back(a[i]);
            i++;
        }
        else{
            if(unionArr.size()==0 or unionArr.back()!=b[j])
                unionArr.push_back(b[j]);
            j++;
        }
    }
    while(i<n1){
        if(unionArr.size()==0 or unionArr.back()!=a[i])
            unionArr.push_back(a[i]);
        i++;
    }
    while(j<n2){
        if(unionArr.size()==0 or unionArr.back()!=b[j])
            unionArr.push_back(b[j]);
        j++;
    }
    return unionArr;
}
int main(){
    int m, n, i, ele;
    vector<int> arr1, arr2, merged;
    cout<<"Enter the first array size: ";
    cin>>m;
    cout<<"Enter the first array elements: ";
    for(i=0;i<m;i++){
        cin>>ele;
        arr1.push_back(ele);
    }
    cout<<"Enter the second array size: ";
    cin>>n;
    cout<<"Enter the second array elements: ";
    for(i=0;i<n;i++){
        cin>>ele;
        arr2.push_back(ele);
    }
    merged = sortedArray(arr1, arr2);
    cout<<"Union of two arrays in sorted order: ";
    for(int i: merged)
        cout<<i<<" ";
    cout<<endl;
}