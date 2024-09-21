#include<iostream>
#include<queue>
using namespace std;
int main(){
    // based on FIFO
    queue<int>q;
    q.push(1);
    q.push(20);
    q.emplace(30);
    q.emplace(40);
    q.pop();
    q.emplace(90);
    q.pop();
    cout<<q.front()<<endl; // expected output 30
    cout<<"Queue size: "<<q.size()<<endl;
}