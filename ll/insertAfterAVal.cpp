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

Node* insertBeforeValue(Node* head, int ele, int val){
    if(head == nullptr) return head;
    Node* temp = head;
    if(head->data == val){
        Node* newHead = new Node(ele);
        newHead->next = head;
        return newHead;
    }
    while(temp->next!=nullptr){
        if(temp->next->data == val){
            Node* newNode = new Node(ele);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    int ele, n, val;
    cout<<"Enter the linked list size: ";
    cin>>n;

    cout<<"Enter the linked list elements: ";
    cin>>ele;
    Node* head = new Node(ele);
    Node* ll = head;
    for(int i = 1;i<n;i++){
        cin>>ele;
        ll->next = new Node(ele);
        ll = ll->next;
    }

    cout<<"Enter the element to be inserted: ";
    cin>>ele;

    cout<<"Enter the value before which the element is to be inserted: ";
    cin>>val;

    Node* newHead = insertBeforeValue(head, ele, val);
    Node* ll2 = newHead;
    cout<<"New linked list: ";
    while(ll2){
        cout<<ll2->data<<" ";
        ll2 = ll2->next;
    }
    cout<<endl;
}