#include<iostream>
#include<queue>
using namespace std;
class MyStack{
    queue<int> q;
    public:
    // TC: O(N)
    void push(int n){
        int s = q.size();
        q.push(n);
        for(int i = 0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    // TC: O(1)
    int pop(){
        int ele = top();
        q.pop();
        return ele;
    }
    // TC:O(1)
    int top(){
        return q.front();
    }
    bool empty(){
        return q.size() == 0;
    }
};
int main(){
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(40);
    cout<<s.top()<<endl;
    s.pop();
    s.push(77);
    s.push(83);
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
}