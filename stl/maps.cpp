#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    // map<int,vector<int>>mappa; // same as dictionaries in python, has unique keys and is sorted
    map<pair<int,int>,int>mappa;
    // map<int,string>mappa;t>mappa;
    // mappa[pair<int,int>(1,2)] = 3;
    // mappa[{1,2}] = 3;
    // mappa.emplace(pair<int,int>(1,2),3);
    mappa.insert(pair<pair<int,int>,int>(pair<int,int>(1,2),3));
    for(auto i: mappa)
        cout<<'{'<<i.first.first<<", "<<i.first.second<<"} : "<<i.second<<endl;
    cout<<endl;
}