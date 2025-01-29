#include<iostream>
#include<stack>
using namespace std;

// Approach 1
// class MyQueue {
//     stack<int> s1, s2;
// public:
//     MyQueue() {
        
//     }
//     // TC: O(2N)
//     void push(int x) {
//         while(s1.size()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(x);
//         while(s2.size()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }
    
//     // TC: O(1)
//     int pop() {
//         int ele = s1.top();
//         s1.pop();
//         return ele;
//     }
    
//     // TC: O(1)
//     int peek() {
//         return s1.top();
//     }
    
//     // TC: O(1)
//     bool empty() {
//         return s1.size() == 0;
//     }
// };

// Approach 2
class MyQueue {
    stack<int> s1, s2;
public:
    // TC: O(1)
    void push(int x) {
        s1.push(x);
    }
    
    // TC: O(N)
    int pop() {
        if(!s2.empty()){
            int ele = s2.top();
            s2.pop();
            return ele;
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int ele = s2.top();
            s2.pop();
            return ele;
        }
    }
    
    // TC: O(N)
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    // TC: O(1)
    bool empty() {
        return s1.empty() and s2.empty();
    }
};
int main(){
    MyQueue q;
    q.push(10);
    q.push(20);
    q.pop();
    cout<<q.peek()<<endl;
    q.push(30);
    q.push(90);
    q.push(20);
    q.pop();
    cout<<q.empty()<<endl;
    cout<<q.peek()<<endl;
}