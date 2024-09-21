#include<iostream>
#include<stack>
using namespace std;
int main(){
    // based on FIFO
    stack<int>st;
    int ele;
    char insertMode = 'y';
    cout<<"Enter an element to initialize stack: ";
    cin>>ele;
    st.emplace(ele);
    while(insertMode!='n'){
        cout<<"Ente an element to insert: ";
        cin>>ele;
        st.push(ele);
        cout<<"Do you want to enter more elements(y for yes/ n for no): ";
        cin>>insertMode;
        cout<<endl;
    }
    cout<<"Stack: ";
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }
    // note that stack swapping is possible with swap operation
    cout<<endl;
}