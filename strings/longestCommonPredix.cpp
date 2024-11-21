#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool allCharSame(vector<string> strs, int minSize, int pt){
    int n = strs.size();
    char ch = strs[0][pt];
    for(int i = 1;i<n;i++){
        if(strs[i][pt]!=ch)
            return false;
    }
    return true;
}
string longestCommonPrefix(vector<string>& strs) {
    int pt = 0, n = strs.size();
    int minSize = INT_MAX;
    string smallestString;
    for(string s: strs){
        int ssize = s.size();
        if(ssize<minSize){
            minSize = ssize;
            smallestString = s;
        }
    }

    while(pt<minSize and allCharSame(strs, minSize, pt))
        pt++;
    return (pt==0)?"":smallestString.substr(0, pt);
}

int main(){
    int n;
    vector<string> stringVector;
    string s;

    cout<<"Enter the number of strings: ";
    cin>>n;

    cout<<"Enter strings separated with spaces: ";
    for(int i = 0;i<n;i++){
        cin>>s;
        stringVector.push_back(s);
    }

    string longestPref = longestCommonPrefix(stringVector);
    cout<<"Longest common prefix of the string is "<<longestPref<<endl;
}