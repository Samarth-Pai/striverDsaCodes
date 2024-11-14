#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// Optimal solution: binary search
// TC: O(log(min(n1, n2)))
// SC: O(1)
int kthElement(vector<int> a, vector<int> b, int n1, int n2, int k){
    if(n1 > n2 ) return kthElement(b, a, n2, n1, k);
    int low = max(0, k - n2), high = min(k, n1);
    int left = k;
    int n = n1 + n2;
    while(low<=high){
        int mid1 = (low + high) >>1;
        int mid2 = left - mid1 ;
        int l1 = INT_MIN, r1 = INT_MAX;
        int l2 = INT_MIN, r2 = INT_MAX;
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];
        if(l1 <= r2 and l2 <= r1)
            return max(l1, l2);
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

int main(){
    int ele, n1, n2, k;
    vector<int> a, b;
    cout<<"Enter the size of first array: ";
    cin>>n1;

    cout<<"Enter the first array elements in sorted order: ";
    for(int i = 0;i<n1;i++){
        cin>>ele;
        a.push_back(ele);
    }

    cout<<"Enter the size of second array: ";
    cin>>n2;

    cout<<"Enter the second array elements in sorted order: ";
    for(int i = 0;i<n2;i++){
        cin>>ele;
        b.push_back(ele);
    }

    cout<<"Enter k: ";
    cin>>k;

    cout<<k<<" th element of the two sorted arrays is "<<kthElement(a, b, n1, n2, k)<<endl;
}