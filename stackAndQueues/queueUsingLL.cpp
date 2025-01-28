#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
    }
};
class qImp{
    public:
    int siz = 0;
    Node *start = nullptr, *end = nullptr;
    // TC: O(1)
    void push(int n){
        Node *temp = new Node(n);
        if(start == nullptr){
            start = temp;
            end = temp;
        }
        else{
            end->next = temp;
            end = end->next;
        }
        siz++;
    }
    // TC: O(1)
    void pop(){
        if(start == nullptr) return;
        Node *temp = start;
        start = start->next;
        delete temp;
        siz--;
    }
    // TC: O(1)
    int top(){
        if(start == nullptr) return -1;
        return start->data; 
    }
    // TC: O(1)
    int size(){
        return siz;
    }
};
int main(){
    qImp q;
    q.push(10);
    q.push(20);
    q.pop();
    cout<<q.top()<<endl;
    q.push(30);
    q.push(90);
    q.push(20);
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.top()<<endl;
}