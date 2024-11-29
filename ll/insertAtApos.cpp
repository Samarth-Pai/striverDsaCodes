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


// Node * insert(Node * head, int n, int pos, int val) {
//     if(pos == 0) return new Node(val);
//     Node* temp = head;
    
// }

int main(){
    int n, ele, k;
    cout<<"Enter the initial size of the linked list: ";
    cin>>n;

    cout<<"Enter the linked list elements: ";
    cin>>ele;
    Node* head = new Node(ele);
    Node* ll = head;
    for(int i = 1;i<n;i++){
        cin>>ele;
        Node* temp = new Node(ele);
        ll->next = temp;
        ll = ll->next;
    }

    cout<<"Enter the element to be inserted at the end: ";
    cin>>ele;
    cout<<"Enter the index of the element to be inserted at: ";
    cin>>k;

    Node* newHead = insert(head, n, k, ele);
    Node* ll2 = newHead;
    cout<<"Linked list after insertion: ";
    while(ll2){
        cout<<ll2->data<<" ";
        ll2 = ll2->next;
    }
    cout<<endl;
    return 0;
}