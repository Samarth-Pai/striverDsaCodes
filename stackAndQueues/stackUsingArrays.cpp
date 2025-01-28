#include<iostream>
#include<vector>
using namespace std;
class stImp{
    int st[100];
    int t = -1;
    public:
    // TC: O(1)
    void push(int n){
        t++;
        st[t] = n;
    }
    // TC: O(1)
    int top(){
        if(t>=0) return st[t];
        return -1;
    }
    // TC: O(1)
    void pop(){
        if(t>=0) t--;
    }
    // TC: O(1)
    int size(){
        return t+1;
    }
};
int main(){
    stImp s;
    s.push(10);
    s.push(20);
    s.push(40);
    cout<<s.top()<<endl;
    s.pop();
    s.push(77);
    s.push(83);
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    
}