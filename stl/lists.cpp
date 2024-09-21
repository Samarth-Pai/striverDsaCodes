#include<iostream>
#include<list>
using namespace std;
int main(){
    // lists also have front operations along with back which makes it different from vectors.
    // since the elements are stored in random memory locations, the elements can only be accessed through iterators
    list<int>lst {10,20,30};
    cout<<"Elements before pushing: ";
    for(int a:lst)
        cout<<a<<' ';
    lst.push_front(5); // pushes an element front of list
    lst.push_back(50); // pushes an element back of list
    cout<<"\nElements after pushing: ";
    for(int i:lst)
        cout<<i<<' ';
    cout<<endl;

     

    // other functions that are common with vector
    // begin, end, rbegin, rend, clear, insert, size, swapff
}