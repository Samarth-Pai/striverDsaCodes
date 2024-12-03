#include <iostream>
#include<stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute approach
// TC: O(2N)
// SC: O(N)
// ListNode* reverseList(ListNode* head) {
//     if(head == nullptr) return head;
//     stack<int> st;
//     ListNode* temp = head;
//     while(temp){
//         st.push(temp->val);
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp){
//         temp->val = st.top();
//         st.pop();
//         temp = temp->next;
//     }
//     return head;
// }

// Optimal solution
// TC: O(N)
// SC: O(1)
ListNode* reverseList(ListNode* head) {
    if(head==nullptr or head->next==nullptr) return head;
    ListNode* temp = head, *prev = nullptr, *front;
    while(temp){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
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

    ListNode* newHead = reverseList(head);
    ListNode* ll2 = newHead;
    cout<<"Linked list after reversing: ";
    while(ll2){
        cout<<ll2->val<<" ";
        ll2 = ll2->next;
    }
    cout<<endl;
}