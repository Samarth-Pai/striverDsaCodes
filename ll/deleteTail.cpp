#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* deleteTail(Node* head){
    if(head==nullptr or head->next==nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next!=nullptr)
        temp = temp->next;
    free(temp->next);
    temp->next = nullptr;
    return head;
}

int main(){
    int ele, n;
    cout<<"Enter linked list size: ";
    cin>>n;

    cout<<"Enter linked list elements: ";
    cin>>ele;
    Node* head = new Node(ele);
    Node* ll = head;

    for(int i=1;i<n;i++){
        cin>>ele;
        ll->next = new Node(ele);
        ll = ll->next;
    }

    cout<<"Linked list after deleting tail: ";
    Node* newHead = deleteTail(head);
    Node* ll2 = newHead;
    while(ll2){
        cout<<ll2->data<<" ";
        ll2 = ll2->next;
    }
    cout<<endl;
}