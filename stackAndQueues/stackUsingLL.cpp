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
class st{
    public:
    Node *t = nullptr;
    int siz = 0;
    // TC: O(1)
    void push(int x){
        Node *temp = new Node(x);
        temp->next = t;
        t = temp;
        siz++;
    }
    // TC: O(1)
    int top(){
        return t->data;
    }
    // TC: O(1)
    void pop(){
        Node *temp = t;
        t = t->next;
        delete temp;
        siz--;
    }
    // TC: O(1)
    int size(){
        return siz;
    }
};
int main(){
    st s;
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