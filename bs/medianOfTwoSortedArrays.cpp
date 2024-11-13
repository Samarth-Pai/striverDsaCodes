#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Brute approach
// TC: O(n1 + n2)
// SC: O(n1 + n2)
// double findMedianSortedArrays(vector<int> a1, vector<int> a2) {
//     vector<int> a3;
//     int i = 0, j = 0, n1 = a1.size(), n2 = a2.size();
//     int n = n1 + n2;
//     while(i<n1 and j<n2){
//         if(a1[i]<a2[j])
//             a3.push_back(a1[i++]);
//         else
//             a3.push_back(a2[j++]);
//     }
//     while(i<n1)
//         a3.push_back(a1[i++]);
//     while(j<n2)
//         a3.push_back(a2[j++]);
    
//     if(n%2)
//         return a3[n/2];
//     else
//         return (a3[n/2] + a3[n/2 + 1])/2.0;
// }

// Better approach
// TC: O(n1 + n2)
// SC: O(1)
// double findMedianSortedArrays(vector<int> a1, vector<int> a2) {
//     vector<int> a3;
//     int i = 0, j = 0, n1 = a1.size(), n2 = a2.size();
//     int n = n1 + n2;
//     int ind2 = n/2;
//     int ind1 = ind2 - 1;
//     int cnt = 0, ind1el = -1, ind2el = -1;
//     while(i<n1 and j<n2){
//         if(a1[i] < a2[j]){
//             if(cnt == ind1) ind1el = a1[i];
//             if(cnt == ind2) ind2el = a1[j];
//             cnt++; i++;
//         }
//         else{
//             if(cnt == ind1) ind1el = a2[i];
//             if(cnt == ind2) ind2el = a2[j];
//             cnt++; j++;
//         }
//     }
//     while(i<n1){
//         if(cnt == ind1) ind1el = a1[i];
//         if(cnt == ind2) ind2el = a1[j];
//         cnt++; i++;
//     }
//     while(j<n2){
//         if(cnt == ind1) ind1el = a2[i];
//         if(cnt == ind2) ind2el = a2[j];
//         cnt++; j++;
//     }

//     if(n%2) return ind2el;
//     return (ind1el + ind2el) / 2.0;
// }


// Optimal solution: binary search
// TC: O(log(min(n1, n2)))
// SC: O(1)
double findMedianSortedArrays(vector<int> a, vector<int> b) {
    int n1 = a.size(), n2 = b.size();
    if (n1>n2)  return findMedianSortedArrays(b, a);
    int n = n1 + n2;
    int low = 0, high = n1;
    int left = (n1 + n2 + 1)/2;
    while(low<=high){
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, r1 = INT_MAX;
        int l2 = INT_MIN, r2 = INT_MAX;
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1 - 1 >=0 ) l1 = a[mid1 - 1];
        if(mid2 - 1 >=0 ) l2 = b[mid2 - 1];
        if(l1<=r2 and l2<=r1){
            if(n%2) return max(l1, l2);
            return (max(l1, l2) + min(r1, r2))/2.0;
        }
        else if(l1 > r2) high =  mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}


int main(){
    int n1, n2, ele;
    vector<int> a1, a2;
    cout<<"Enter the size of first array: ";
    cin>>n1;
    cout<<"Enter the first array elements in sorted order: ";
    for(int i = 0;i<n1;i++){
        cin>>ele;
        a1.push_back(ele);
    }

    cout<<"Enter the size of second array: ";
    cin>>n2;
    cout<<"Enter the second array elements in sorted order: ";
    for(int i = 0;i<n2;i++){
        cin>>ele;
        a2.push_back(ele);
    }

    cout<<"Median of two sorted arrays is "<<findMedianSortedArrays(a1, a2)<<endl;
}