#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int>s; // unique and sorted, iterable
    // all operations are of O(log n)
    int ele;
    char yon='y';
    cout<<"Please include the elements 6 and 90\n";
    cout<<"Enter an element to initialize the set: ";
    cin>>ele;
    s.insert(ele);
    while(yon!='n'){
        cout<<"Enter the element to insert: ";
        cin>>ele;
        s.insert(ele);
        cout<<"\nSet: ";
        for(int i:s)
            cout<<i<<' ';
        cout<<"\nDo you want to add some more elements(y/n): ";
        cin>>yon;
        cout<<endl; 
    }
    set<int>::iterator it1 = s.find(6);
    set<int>::iterator it2 = s.find(90);

    s.erase(it1,it2); // erases the elements between 6(inclusive) and 90(exclusive)

    cout<<"\nSet after erasing: ";
    for(int i:s)
        cout<<i<<' ';
    cout<<endl<<s.count(90);
    cout<<endl;
}