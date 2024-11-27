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

Node* deleteNode(Node* head, int val){
    if(head == nullptr) return head;
    Node* temp = head, *prev = temp;
    if(head->data == val){
        head = head->next;
        free(temp);
        return head;
    }
    while(temp!=nullptr){
        if(temp->data == val){
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    int ele, n;
    cout<<"Enter the size of linked list: ";
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

    cout<<"Enter the element to be deleted: ";
    cin>>ele;

    Node* newHead = deleteNode(head, ele);

    cout<<"Linked list after deletion: ";
    Node* ll2 = newHead;
    while(ll2){
        cout<<ll2->data<<" ";
        ll2 = ll2->next;
    }
    cout<<endl;
    return 0;
}
