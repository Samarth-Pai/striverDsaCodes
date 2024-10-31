#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long sumOfArr(vector<int> arr){
    long long sum = 0;
    for(int i: arr)
        sum+=i;
    return sum;
}
int daysRequired(vector<int> weights, int cap){
    int days = 1, load = 0;
    for(int w: weights){
        if(load+w > cap){
            days++;
            load = w;
        }
        else
            load+=w;
    }
    return days;
}


// Brute approach
// TC: O((sum-max)*N)
// SC: O(1)
// int shipWithinDays(vector<int> weights, int d) {
//     int cap, maxi = *max_element(weights.begin(), weights.end()), reqDays;
//     for(cap = maxi;cap<sumOfArr(weights);cap++){
//         reqDays = daysRequired(weights, cap);
//         if(reqDays<=d){
//             return cap;
//         }
//     }
//     return -1;
// }


// Optimal solution
// TC: O(log2(sum - max)*N)
int shipWithinDays(vector<int> weights, int d){
    int low = *max_element(weights.begin(), weights.end()), high = sumOfArr(weights), mid, reqDays;

    while(low<=high){
        mid = (low + high)/2;
        reqDays = daysRequired(weights, mid);
        if(reqDays<=d)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main(){
    int ele, n, d;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;

    cout<<"Enter the wieghts of each packages to ship: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Enter no. of days: ";
    cin>>d;

    cout<<"Least capacity of the ship to load all the packages under "<<d<<" days is "<<shipWithinDays(arr, d)<<endl;
    // cout<<"Jay "<<daysRequired(arr, d)<<endl;
}