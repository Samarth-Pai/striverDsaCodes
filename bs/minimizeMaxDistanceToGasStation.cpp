#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// Brute approach
// TC: O(k*n + n)
// SC: O(n-1)
// double minimiseMaxDistance(vector<int> &arr, int k){
//     int n = arr.size();
//     double sectionLen, diff;
//     vector<int> howMany(n-1);
//     for(int gas = 1;gas<=k;gas++){
//         double maxVal = -1;
//         int maxInd = -1;
//         for(int i = 0;i<n-1;i++){
//             diff = arr[i+1] - arr[i];
//             sectionLen = diff/(howMany[i]+1);
//             if (maxVal<sectionLen){
//                 maxVal = sectionLen;
//                 maxInd = i;
//             }
//         }
//         howMany[maxInd]++;
//     }
//     double maxAns = -1;
//     for(int i = 0;i<n-1;i++){
//         double diff = arr[i+1] - arr[i];
//         double sectionLen = diff/(howMany[i] + 1);
//         maxAns = max(maxAns, sectionLen);
//     }
//     return maxAns;
// }


// Better approach: using priority queue
// TC: O(n*logn + k*logn)
// SC: O(n-1 + n)
// double minimiseMaxDistance(vector<int> &arr, int k){
//     int n = arr.size();
//     double sectionLen, diff;
//     vector<int> howMany(n-1);
//     priority_queue<pair<double, int>> pq;
//     for(int i = 0;i<n-1;i++)
//         pq.push({arr[i+1]-arr[i], i});
//     for(int gas = 1;gas<=k;gas++){
//         pair<double, int> tp = pq.top(); pq.pop();
//         int secInd = tp.second;
//         howMany[secInd]++;
//         double diff = arr[secInd + 1] - arr[secInd];
//         double newSecLen = diff/(howMany[secInd] + 1);
//         pq.push({newSecLen, secInd});
//     }
//     return pq.top().first;
// }


int noOfGasStationsRequired(double dist, vector<int> arr){
    int cnt = 0;
    for(int i = 0;i<arr.size() - 1;i++){
        int numberInBetween = (arr[i+1] - arr[i])/dist;
        if((arr[i+1] - arr[i])/dist == numberInBetween*dist)
            numberInBetween--;
        cnt+=numberInBetween;
    }
    return cnt;
}

// Optimal solution: binary search
// TC: O(n + n*logn)
// SC: O(1)
double minimiseMaxDistance(vector<int> arr, int k){
    int n = arr.size();
    double low = 0;
    double high = 0;
    for(int i = 0;i<n-1;i++) high = max(high, (double)(arr[i+1] - arr[i]));
    double diff = 1e-6;
    while(high-low>diff){
        double mid = (low + high)/2.0;
        int cnt = noOfGasStationsRequired(mid, arr);
        if(cnt>k) low = mid;
        else high = mid;
    }
    return high;
}



int main(){
    int n, ele, k;
    vector<int> stations;
    cout<<"Enter the number of gas stations: ";
    cin>>n;
    cout<<"Enter the gas stations coordinates in sorted order: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        stations.push_back(ele);
    }

    cout<<"Enter the no. of more gas stations to be implemented: ";
    cin>>k;
    cout<<"Maximum of minimum distance to each gas stations is "<<minimiseMaxDistance(stations, k)<<endl;

    return 0;
}