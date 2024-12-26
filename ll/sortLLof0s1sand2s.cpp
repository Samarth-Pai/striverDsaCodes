#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
// Brute appoach
// TC: O(2N)
// SC: O(1)
// Node* segregate(Node* head) {
//     Node *temp = head;  
//     int cnt0 = 0, cnt1 = 0, cnt2 = 0;
//     while(temp){
//         if(temp->data==0) cnt0++;
//         else if(temp->data==1) cnt1++;
//         else cnt2++;
//         temp = temp->next;
//     }
//     temp = head;
//     while(cnt0){
//         temp->data = 0;
//         temp = temp->next;
//         cnt0--;
//     }
//     while(cnt1){
//         temp->data = 1;
//         temp = temp->next;
//         cnt1--;
//     }
//     while(cnt2){
//         temp->data = 2;
//         temp = temp->next;
//         cnt2--;
//     }
//     return head;
// }

// Optimal solution
// TC: O(N)
// SC: O(N)
Node* segregate(Node* head) {
    if(head==nullptr or head->next==nullptr) return head;
    Node *zeroHead = new Node(-1); Node *zero = zeroHead;
    Node *oneHead = new Node(-1); Node *one = oneHead;
    Node *twoHead= new Node(-1); Node *two = twoHead;
    Node *temp = head;

    while(temp){
        if(temp->data==0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    two->next = nullptr;
    one->next = twoHead->next;
    zero->next = oneHead->next;
    Node *newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}
int main(){
    int ele, n;
    cout<<"Enter linked list size: ";
    cin>>n;
    cout<<"Enter linked list elements of 0s, 1s and 2s: ";
    cin>>ele;
    Node *head = new Node(ele);
    Node *ll = head;
    for(int i=1;i<n;i++){
        cin>>ele;
        Node *temp = new Node(ele);
        ll->next = temp;
        ll = ll->next;
    }
    Node *newHead = segregate(head);
    Node *ll2 = newHead;
    cout<<"Linked list in sorted order: ";
    while(ll2){
        cout<<ll2->data<<" ";
        ll2 = ll2->next;
    }
    cout<<endl;
}