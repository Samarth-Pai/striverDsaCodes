#include<iostream>
// #include<set>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int>s; // unique but unsorted(randomised)
    // all operations are of time complexity of O(1) but the worst case(that happens 1 in 1,000,000 times) it goes upto O(n))
    //lower_bound and upper_bount functions do not work
    int ele;
    char yon='y';
    cout<<"Enter an element to initialize the set: ";
    cin>>ele;
    s.insert(ele);
    while(yon!='n'){
        cout<<"Enter the element to insert: ";
        cin>>ele;
        s.insert(ele);
        cout<<"\nUnorderedset: ";
        for(int i:s)
            cout<<i<<' ';
        cout<<"\nDo you want to add some more elements(y/n): ";
        cin>>yon;
        cout<<endl;
    }
}