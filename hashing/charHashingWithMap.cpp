#include<iostream>
#include<map>
using namespace std;
int main(){
    string s;
    cout<<"Inject a string: ";
    cin>>s;
    
    // precompute
    map<char,int>mpp;
    for(char c:s)
        mpp[c]++;

    // iterate through the map
    for(auto it: mpp)
        cout<<it.first<<" : "<<it.second<<endl;
    
    // fetch
    char q;
    
    while(true){
        cout<<"Enter query: ";
        cin>>q;
        cout<<"Occurance of "<<q<<" is "<<mpp[q]<<endl<<endl;
    }
}