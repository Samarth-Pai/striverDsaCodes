#include<iostream>
#include<vector>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(1)
// int maxScore(vector<int>& cardPoints, int k) {
//     int maxi = 0, n = cardPoints.size(), score;
//     for(int i = n-k;i<=n;i++){
//         score = 0;
//         for(int j = i;j<i+k;j++){
//             score += cardPoints[j%n];
//         }
//         maxi = max(maxi, score);
//     }
//     return maxi;
// }

// Optimal solution
// TC: O(N)
// SC: O(1)
int maxScore(vector<int>& cardPoints, int k) {
    int maxi, n = cardPoints.size(), lsum = 0, rsum = 0;
    for(int i = 0;i<k;i++){
        lsum+=cardPoints[i];
    }
    maxi = lsum;
    for(int i = k-1;i>=0;i--){
        lsum -= cardPoints[i];
        rsum += cardPoints[n-k+i];
        maxi = max(maxi, lsum + rsum);
    }
    return maxi;
}

int main(){
    int n, ele, k;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter k: ";
    cin>>k;
    cout<<"Maximum points you can obtain from the cards is "<<maxScore(arr, k) <<endl;
}