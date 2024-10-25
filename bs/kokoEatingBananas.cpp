#include<iostream>
#include<vector>
#include<math.h>
#include<climits>

using namespace std;

int findMax(vector<int> arr){
    int maxi = INT_MIN;
    for(int i: arr)
        maxi = max(maxi, i);

    return maxi;
}
long long totalTimeTaken(vector<int> piles, int hrs){
    long long totalHrs = 0;
    for(int i = 0;i<piles.size();i++)
        totalHrs+=ceil((double)piles[i]/(double)hrs);
    return totalHrs;
}

// Brute approach 
// TC: O(max(arr)*n)
// SC: O(1)
// int minEatingSpeed(vector<int> piles, int h) {
//     int maxi = findMax(piles);
//     for(int i = 1;i<=maxi;i++){
//         int timeTaken = totalTimeTaken(piles, i);
//         if(timeTaken<=h)    
//             return i;
//     }
//     return maxi;
// }


int minEatingSpeed(vector<int> piles, int h){
    int low = 1, high = findMax(piles), ans = INT_MAX;
    while(low<=high){
        int mid = (low + high)/2;
        long long timeTaken = totalTimeTaken(piles, mid);
        if(timeTaken<=h)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main(){
    int ele, n, h;
    vector<int> piles;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements in sorted order: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        piles.push_back(ele);
    }

    cout<<"Enter the time limit h for koko: ";
    cin>>h;

    cout<<"Min speed that koko can take is "<<minEatingSpeed(piles, h)<<"/ hour"<<endl;
}