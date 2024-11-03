#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

bool canWePlace(vector<int> stalls, int dist, int k){
    int cntCows = 1, last = stalls[0];
    for(int i = 1;i<stalls.size();i++){
        if(stalls[i]-last>=dist){
            cntCows++;
            last = stalls[i];
        }
        if(cntCows>=k) return true;
    }
    return false; 
}

// Brute approach
// TC: O((max-min)*N)
// SC: O(1)
// int aggressiveCows(vector<int> stalls, int k)
// {
//     sort(stalls.begin(), stalls.end());
//     int mini = *min_element(stalls.begin(), stalls.end()), maxi = *max_element(stalls.begin(), stalls.end());
//     for(int i = 0;i<maxi-mini;i++){
//         if(canWePlace(stalls, i, k))
//             continue;
//         else
//             return i-1;
//     }
//     return -1;
// }


// Optimal soltion
// TC: O((max - min)*log_2N)
// SC: O(1)
int aggressiveCows(vector<int> stalls, int k){
    sort(stalls.begin(), stalls.end());
    int mini = stalls[0], maxi = stalls[stalls.size()-1];
    int low = 1, high = maxi - mini, mid;
    while(low<=high){
        mid = (low + high)/2;
        if(canWePlace(stalls, mid, k))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int main(){
    int ele, n, k;
    vector<int> stalls;
    cout<<"Enter the no. of stalls: ";
    cin>>n;

    cout<<"Enter the stall coordinates: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        stalls.push_back(ele);  
    }

    cout<<"Enter the no. of cows: ";
    cin>>k;
    cout<<"Maximum of minimum distance between each cows is: "<<aggressiveCows(stalls, k)<<endl;

}