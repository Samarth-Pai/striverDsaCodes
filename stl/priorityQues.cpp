#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>pq; // always keeps the greatest element at the top, also known as max heap
    pq.push(10);
    pq.push(90);
    pq.push(1);
    pq.emplace(9);
    pq.push(50);
    pq.pop();
    cout<<pq.top()<<endl;

    priority_queue<int,vector<int>,greater<int>>pq2; // always keeps the lowest value element at the top, also known as min heap
    pq2.push(10);
    pq2.push(90);
    pq2.push(1);
    pq2.emplace(9);
    pq2.push(50);
    pq2.pop();
    cout<<pq2.top()<<endl;
}