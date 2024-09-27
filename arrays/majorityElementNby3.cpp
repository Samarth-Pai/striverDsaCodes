#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;

// Brute approach
// TC: O(N^2)
// SC: O(1)
// vector<int> majorityElement(vector<int>a) { 
//     vector<int>ls;
//     int count, n = a.size();
//     for(int i: a){
//         if(ls.size()==0 or ls[0]!=i){
//             count = 0;
//             for(int j: a)
//                 if(j==i) count++;
//             if(count>n/3)
//                 ls.push_back(i);
//         }
//         if(ls.size()==2) break;
//     }
//     return ls;
// }

// Better approach: hashing
// TC: O(NlogN)
// SC: O(N)
// vector<int> majorityElement(vector<int>a){
//     vector<int>ls;
//     map<int, int> mpp;
//     int mm = a.size()/3 + 1;
//     for(int i: a){
//         mpp[i]++;
//         if(mm==mpp[i])
//             ls.push_back(i);
//     }
//     return ls;
// }

// Optimal solution: Boyer Moore's voting algorithm
// TC: O(2N)
// SC: O(1)
vector<int> majorityElement(vector<int>a){
    int ele1 = INT_MIN, ele2 = INT_MIN, cnt1 = 0, cnt2 = 0;
    for(int i: a){
        if (cnt1==0 and i!=ele2){
            ele1 = i;
            cnt1++;
        }
        else if (cnt2==0 and i!=ele1)
        {
            ele2 = i;
            cnt2++;
        }
        else if (ele1==i) cnt1++;
        else if (ele2==i) cnt2++;
        else{
            cnt1--; cnt2--;
        }
    }

    vector<int>ls;
    cnt1 =0, cnt2 = 0;
    for(int i: a){
        if(i==ele1) cnt1++;
        if(i==ele2) cnt2++;
    }
    int mm = a.size()/3 + 1;
    if(cnt1>=mm) ls.push_back(ele1);
    if(cnt2>=mm) ls.push_back(ele2);
    return ls;
}
int main(){
    int n, i, ele;
    vector<int>arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements and make sure to repeat two elements that appears more than n/3 times : ";
    for(i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    vector<int> majority = majorityElement(arr);
    cout<<"Majority elements: ";
    for(int i: majority) cout<<i<<" ";
    cout<<endl;
}