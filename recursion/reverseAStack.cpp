#include<iostream>
#include<stack>
using namespace std;
// Iterative approach
// TC: O(N)
// SC: O(N)
// void Reverse(stack<int> &st){
//     stack<int> s;
//     while(not st.empty()){
//         s.push(st.top());
//         st.pop();
//     }
//     st = s;
// }

// Recursive approach
// TC: O(2N)
// SC: O(N)
void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(temp);
}
void Reverse(stack<int> &st){
    if(st.empty() or st.size()==1) return;
    int ele = st.top();
    st.pop();
    Reverse(st);
    insertAtBottom(st, ele);
}

void printStack(stack<int> s){
    if(s.empty()) return;
    int ele = s.top();
    s.pop();
    printStack(s);
    cout<<ele<<" ";
}

int main(){
    int n, ele;
    stack<int> st;
    cout<<"Enter the number of elements in the stack: ";
    cin>>n;
    cout<<"Enter the stack elments with top as last element: ";
    for(int i = 0;i < n;i++){
        cin>>ele;
        st.push(ele);
    }

    Reverse(st);

    cout<<"Stack after reversing: ";
    printStack(st);
    cout<<endl;
}