#include<iostream>
#include<vector>
using namespace std;
// Brute force approach
// Time complexity: O(n1*n2)
// Space complexity: O(n2)(for storing visited) + O(n1+n2)(for returning answer)
// vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
// {
// 	vector<int>intersection;
//     vector<bool>visited(m);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr1[i]==arr2[j] and visited[j]==false){
//                 intersection.push_back(arr1[i]);
//                 visited[j] = true;
//                 break;
//             }
//             if(arr2[j]>arr1[i])
//                 break;
//         }
//     }
//     return intersection;
// }

// Optimal solution: two pointer approach
// Time complexity: O(n1 + n2)
// Space complexity: O(n1 + n2)

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){
    int i = 0, j = 0;
    vector<int>intersection;
    while(i<n and j<m){
        if(arr1[i]<arr2[j])
            i++;
        else if(arr2[j]<arr1[i])
            j++;
        else{
            intersection.push_back(arr1[i]);
            i++;
            j++; 
        }
    }
    return intersection;
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
    merged = findArrayIntersection(arr1, m, arr2, n);
    cout<<"Intersection of two arrays in sorted order: ";
    for(int i: merged)
        cout<<i<<" ";
    cout<<endl;
}