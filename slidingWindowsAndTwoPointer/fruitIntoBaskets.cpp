#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(1)
// int totalFruit(vector<int>& fruits) {
//     int n = fruits.size(), maxi = 0, i, j;
//     for(i = 0;i<n;i++){
//         set<int> s;
//         for(j = i;j<n;j++){
//             s.insert(fruits[j]);
//             if(s.size()>2) break;
//         }
//         maxi = max(maxi, j - i);
//     }
//     return maxi;
// }

// Better approach: shrinking sliding window
// TC: O(2N)
// SC: O(3)
// int totalFruit(vector<int>& fruits){
//     int n = fruits.size(), maxi = 0, l = 0, r = 0;
//     map<int, int> mappa;
//     while(r < n){
//         mappa[fruits[r]]++;
//         if(mappa.size()>2){
//             maxi = max(maxi, r - l);
//             while(mappa.size()>2){
//                 mappa[fruits[l]]--;
//                 if(mappa[fruits[l]] == 0) mappa.erase(fruits[l]);
//                 l++;
//             }
//         }
//         r++;
//     }
//     return max(maxi, r - l);
// }

// Optimal solution: non-shrinking sliding window
// TC: O(N)
// SC: O(3)
int totalFruit(vector<int>& fruits){
    int n = fruits.size(), maxi = 0, l = 0, r = 0;
    map<int, int> mappa;
    while(r < n){
        mappa[fruits[r]]++;
        if(mappa.size()>2){
            mappa[fruits[l]]--;
            if(mappa[fruits[l]] == 0) mappa.erase(fruits[l]);
            l++;
        }
        maxi = max(maxi, r - l + 1);
        r++;
    }
    return maxi;
}

int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Maximum fruits carried by two baskets are "<<totalFruit(arr)<<endl;
}