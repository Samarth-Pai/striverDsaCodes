#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

string frequencySort(string &s) {
    map<char, int>mpp;
    for(char c: s)
        mpp[c]++;

    vector<pair<char, int>> mppVec(mpp.begin(), mpp.end());
    sort(mppVec.begin(), mppVec.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
    });

    string res;
    for(pair<char, int> p: mppVec)
        res+=string(p.second, p.first);
    

    return res;
}


int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;

    cout<<"String with sorted with respect to frequency of characters: "<<frequencySort(s)<<endl;
}