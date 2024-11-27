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

// Assuming k is 0 based index
Node* deleteNode(Node* head, int k){
    if(head==nullptr) return head;
    Node* temp = head, *prev = nullptr;
    if(k==0){   
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    while(temp!=nullptr){
        if(cnt==k){
            // prev->next = prev->next->next;
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head;
}
int main(){
    int ele, n, k;
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

    cout<<"Enter kth position to the node to be deleted from the linked list: ";
    cin>>k;

    Node* newHead = deleteNode(head, k);
    Node* newLl = newHead;
    cout<<"Linked list after deletion: ";
    while (newLl)
    {
        cout<<newLl->data<<" ";
        newLl = newLl->next;
    }
    cout<<endl;
    return 0;
}