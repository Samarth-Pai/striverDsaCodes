#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
// TC: O(2NlogN + N)
// SC: O(1)
int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0, j = 0, n = arr.size(), count = 0, maxCount = 1;
    while(i<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}
int main(){
    int n, ele1, ele2;
    vector<int> arr, dep;
    cout<<"Enter no. of times: ";
    cin>>n;
    cout<<"Enter each train timings:"<<endl;
    for(int i = 0;i<n;i++){
        cin>>ele1>>ele2;
        arr.push_back(ele1);
        dep.push_back(ele2);
    }
    cout<<"Minimum platforms: "<<findPlatform(arr, dep)<<endl;
}