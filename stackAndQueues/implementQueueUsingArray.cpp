#include<iostream>
using namespace std;
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;
public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
void MyQueue::push(int n){
    if(rear == 100005) return;
    arr[rear++] = n;
}
int MyQueue::pop(){
    if(front == rear) return -1;
    int ele = arr[front];
    arr[front] = -1;
    front++;
    if(front == rear){
        rear = 0;
        front = 0;
    }
    return ele;
}
int main(){
    MyQueue q;
    q.push(2);
    q.push(3);
    cout<<q.pop()<<endl;
    q.push(4);
    cout<<q.pop()<<endl;
}