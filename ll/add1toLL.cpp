#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* reverseList(Node* head) {
    if(head==nullptr or head->next==nullptr) return head;
    Node* temp = head, *prev = nullptr, *front;
    while(temp){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// Iterative approach
// Node* addOne(Node* head) {
//     int carry = 1;
//     head = reverseList(head);
//     Node *temp = head;
//     while(temp){
//         temp->data = temp->data+carry;
//         if(temp->data<10){
//             carry = 0;
//             break;
//         }
//         else{
//             temp->data = 0;
//             carry = 1;
//         }
//         temp = temp->next;
//     }
//     if(carry){
//         Node *oneNode = new Node(1);
//         head = reverseList(head);
//         oneNode->next = head;
//         return oneNode;
//     }
//     head = reverseList(head);
//     return head;
// }

int helper(Node *temp){
    if(temp==nullptr) return 1;
    int carry = helper(temp->next);
    temp->data = temp->data+carry;
    if(temp->data<10)
        return 0;
    temp->data = 0;
    return 1;
}
// Recursive approach: backtracking 
// TC: O(N)
// SC: O(N) recursive stack space
Node* addOne(Node* head) {
    int carry = helper(head);
    if(carry){
        Node *oneNode = new Node(1);
        oneNode->next = head;
        return oneNode;
    }
    return head;
}
int main(){
    int n, ele;
    cout<<"Enter no. of digits: ";
    cin>>n;
    cout<<"Enter each digit separated with a space: ";
    cin>>ele;
    Node *head = new Node(ele);
    Node *ll = head;
    for(int i=1;i<n;i++){
        cin>>ele;
        ll->next = new Node(ele);
        ll = ll->next;
    }
    Node *newHead = addOne(head);
    Node *ll2 = newHead;
    cout<<"Linked list after adding 1 to the number: ";
    while(ll2){
        cout<<ll2->data<<" ";
        ll2 = ll2->next;
    }
    cout<<endl;
}