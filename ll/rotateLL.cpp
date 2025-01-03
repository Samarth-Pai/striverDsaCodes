#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *findKthNode(ListNode *head, int k){
    ListNode *temp = head;
    while(k>1){
        k--;
        temp = temp->next;
    }
    return temp;
}
ListNode* rotateRight(ListNode* head, int k) {
    if(head==nullptr or head->next==nullptr) return head;
    ListNode *tail = head;
    int len = 1;
    while(tail->next){
        len++;
        tail = tail->next;
    }
    if(k%len==0) return head;
    k = k%len;
    tail->next = head;
    ListNode *newTail = findKthNode(head, len-k);
    head = newTail->next;
    newTail->next = nullptr;
    return head;
}
int main(){
    int n, ele, k;
    cout<<"Enter the linked list size: ";
    cin>>n;

    cout<<"Enter the linked list elements: ";
    cin>>ele;
    ListNode *head = new ListNode(ele);
    ListNode *ll = head;
    for(int i = 1;i<n;i++){
        cin>>ele;
        ll->next = new ListNode(ele);
        ll = ll->next;
    }
    cout<<"Enter k times to be rotated: ";
    cin>>k;

    ListNode *newHead = rotateRight(head, k);
    ll = newHead;
    cout<<"New linked list: ";
    while(ll){
        cout<<ll->val<<" ";
        ll = ll->next;
    }
    cout<<endl;
    return EXIT_SUCCESS;
}