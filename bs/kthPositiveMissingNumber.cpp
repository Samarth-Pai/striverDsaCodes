#include<iostream>
#include<vector>
using namespace std;


// TC: O(N)
// SC: O(1)
// int findKthPositive(vector<int> arr, int k) {
//     for(int i: arr)
//         if(i<=k) k++;
//         else break;
//     return k;
// }

// TC: O(log_2N)
// SC: O(1)
int findKthPositive(vector<int> arr, int k) {
    int low = 0, high = arr.size() - 1, missing, mid;
    while(low<=high){
        mid = (low + high)/2;
        missing = arr[mid] - (mid + 1);
        if(missing<k)
            low = mid + 1;
        else
            high = mid - 1;
        
    }
    // return high + 1 + k;
    return low + k;
}
int main(){
    int ele, n, k;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter "<<n<<" natural numbers in sorted order: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<k<<" missing number in the array is "<<findKthPositive(arr, k)<<endl;
}