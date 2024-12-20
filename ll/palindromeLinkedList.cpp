#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute approach: using stack
// TC: O(2N)
// SC: O(N)
// bool isPalindrome(ListNode* head) {
//     stack<int> st;
//     ListNode* temp = head;
//     while(temp){
//         st.push(temp->val);
//         temp = temp->next;
//     }

//     temp = head;
//     while(temp){
//         if(st.top()!=temp->val)
//             return false;
//         st.pop();
//         temp = temp->next;
//     }
//     return true;
// }

// Optimal solution
// TC: O(2N)
// SC: O(1)
ListNode* reverseLL(ListNode* head) {
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

bool isPalindrome(ListNode* head){
    if(head==nullptr or head->next==nullptr) return true;   
    ListNode* slow = head, *fast = head;
    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *newHead = reverseLL(slow->next);
    ListNode *first = head, *second = newHead;
    while(second){
        if(first->val!=second->val){
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}

int main(){
    int ele, n;
    cout<<"Enter the linked list size: ";
    cin>>n;
    cout<<"Enter the linked list elements: ";
    cin>>ele;
    ListNode *head = new ListNode(ele);
    ListNode *ll = head;
    for(int i = 0;i<n-1;i++){
        cin>>ele;
        ll->next = new ListNode(ele);
        ll = ll->next;
    }
    
    if(isPalindrome(head))
        cout<<"The given linked list is a palindrome"<<endl;
    else
        cout<<"The given linked list is not a palindrome"<<endl;
}