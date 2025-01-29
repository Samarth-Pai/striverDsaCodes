#include<iostream>
#include<stack>
#include<climits>
using namespace std;
// TC: O(1)
// SC: O(2N)
// class MinStack {
//     stack<pair<int, int>> st;
// public:
//     void push(int val) {
//         if(st.empty()) st.push({val, val});
//         else st.push({val, min(val, st.top().second)});
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }
// };
// TC: O(1)
// SC: O(N)
class MinStack {
    stack<long long> st;
    long long mini = INT_MAX;
public:
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val >= mini) st.push(val);
            else{
                st.push(2LL*val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        long long n = st.top();
        st.pop();
        if(n<mini) mini = 2LL*mini - n;
    }
    
    int top() {
        long long n = st.top();
        return (n<mini)?mini:n;
    }
    
    int getMin() {
        return mini;
    }
};
int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<minStack.getMin()<<endl; // return -3
    minStack.pop();
    cout<<minStack.top()<<endl;    // return 0
    cout<<minStack.getMin()<<endl; // return -2
}