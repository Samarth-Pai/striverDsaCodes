#include<iostream>
#include<vector>
#include<map>
using namespace std;
bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size()%groupSize) return false;
    map<int, int> mappa;
    for(int i: hand)
        mappa[i]++;
    for(pair<int, int> p: mappa){
        if(p.second == 0) continue;
        while(p.second--){
            for(int i = p.first; i < p.first + groupSize; i++){ 
                if(mappa[i] == 0)
                    return false;
                mappa[i]--;
            }
        }
    }
    return true;
}
int main(){
    int n, ele, groupSize;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter group size: ";
    cin>>groupSize;
    if(isNStraightHand(arr, groupSize))
        cout<<"Alice can rearrange"<<endl;
    else
        cout<<"Alice could`nt"<<endl;
}