#include<iostream>
#include<set>
using namespace std;
int main(){
    multiset<int>ms; // sorted but not unique
    int ele;
    char yon='y';
    cout<<"Please try including repetitive elements\n";
    cout<<"Enter an element to initialize the multiset: ";
    cin>>ele;
    ms.insert(ele);
    while(yon!='n'){
        cout<<"Enter the element to insert: ";
        cin>>ele;
        ms.insert(ele);
        cout<<"\nMultiset: ";
        for(int i:ms)
            cout<<i<<' ';
        cout<<"\nDo you want to add some more elements(y/n): ";
        cin>>yon;
        cout<<endl; 
    }
    cout<<"Enter an element to remove: ";
    cin>>ele;
    ms.erase(ele); // note that passing address of an element will erase only one occurance
    cout<<"Element after erasing: ";
    for(int i: ms)
        cout<<i<<' ';
    cout<<endl;
}