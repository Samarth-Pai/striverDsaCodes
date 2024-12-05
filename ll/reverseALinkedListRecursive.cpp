#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Recursive approach
// TC: O(N)
// SC: O(N) recursive stack space
ListNode* reverseList(ListNode* head) {
    if(head == nullptr or head->next == nullptr) return head;
    ListNode* newHead = reverseList(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main(){
    int ele, n;
    cout<<"Enter the linked list size: ";
    cin>>n;

    cout<<"Enter the linked list elements: ";
    cin>>ele;
    ListNode* head = new ListNode(ele);
    ListNode* ll = head;
    for(int i = 1;i<n;i++){
        cin>>ele;
        ll->next = new ListNode(ele);
        ll = ll->next;
    }


    cout<<"Linked list after reversing: ";
    ListNode* newHead = reverseList(head);
    ListNode* ll2 = newHead;
    while(ll2){
        cout<<ll2->val<<" ";
        ll2 = ll2->next;
    }
    cout<<endl;
}