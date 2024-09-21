#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,string>um; // unique and randomised. 0(1) and O(n) for blue moon
    // note that the key can be only individual datatype like int, char and not pair, vectors etc.
    int ele1;
    string ele2;
    char mode='y';
    while(mode!='n'){
        cout<<"\nEnter a key(number) value(word) pair to add to the unordered set: ";
        cin>>ele1>>ele2;
        cout<<"Unordered set: \n";
        um.emplace(ele1,ele2);
        for(auto i: um)
            cout<<i.first<<" : "<<i.second<<endl;
        cout<<"Do you want to continue?(y/n): ";
        cin>>mode;
    }
    cout<<endl;
}