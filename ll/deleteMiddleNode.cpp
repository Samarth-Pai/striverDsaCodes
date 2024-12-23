#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Brute approach
// TC: O(N + N/2)
// SC: O(1)
// ListNode* deleteMiddle(ListNode* head) {
//     if(head==nullptr or head->next==nullptr) return nullptr;
//     int cnt = 0, mid;
//     ListNode *temp = head;
//     while(temp){
//         cnt++;
//         temp = temp->next;
//     }
//     mid = cnt/2;
//     temp = head;
//     while(mid-1){
//         temp = temp->next;
//         mid--;
//     }
//     ListNode *middleNode = temp->next;
//     temp->next = temp->next->next;
//     delete middleNode;
//     return head;
// }

// Optmial solution
// TC: O(N/2)
// SC: O(1)
ListNode* deleteMiddle(ListNode* head) {
    if(head==nullptr or head->next==nullptr) return nullptr;
    ListNode *slow = head, *fast = head;
    fast = fast->next->next;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *middleNode = slow->next;
    slow->next = slow->next->next;
    delete middleNode;
    return head;
}

int main(){
    int ele, n;
    cout<<"Enter the linked list size: ";
    cin>>n;
    cout<<"Enter the linked list elements: ";
    cin>>ele;
    ListNode* head = new ListNode(ele);
    ListNode *ll = head;
    for(int i = 1;i<n;i++){
        cin>>ele;
        ll->next = new ListNode(ele);
        ll = ll->next;
    }

    ListNode *newHead = deleteMiddle(head);
    ListNode *ll2 = newHead;
    cout<<"Linked list after deleting the middle node: ";
    while(ll2){
        cout<<ll2->val<<" ";
        ll2 = ll2->next;
    }
    cout<<endl;
}