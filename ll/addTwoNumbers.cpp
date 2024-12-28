#include<iostream>
using namespace std;struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if(head == nullptr or head->next == nullptr) return head;
    ListNode* newHead = reverseList(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

// TC: O(max(N1, N2))
// SC: O(max(N1, N2))
ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
    ListNode *l1 = head1, *l2 = head2;
    ListNode *dummyNode = new ListNode(-1);
    ListNode *curr = dummyNode;
    int carry = 0, sum;
    while(l1 or l2){
        sum = carry;
        if(l1) sum+=l1->val;
        if(l2) sum+=l2->val;
        ListNode *newNode =new ListNode(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr = curr->next;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    if(carry){
        curr->next = new ListNode(carry);
        curr = curr->next;
    }
    return dummyNode->next;
}

int main(){
    int n1, n2, ele;
    cout<<"Enter the number of digits of first number: ";
    cin>>n1;

    cout<<"Enter the first number with digit separated by space in reversed order: ";
    cin>>ele;
    ListNode *head1 = new ListNode(ele);
    ListNode *l1 = head1;
    for(int i=1;i<n1;i++){
        cin>>ele;
        l1->next = new ListNode(ele);
        l1 = l1->next;
    }
    
    cout<<"Enter the number of digits of second number: ";
    cin>>n2;
    
    cout<<"Enter the second number with digit separated by space in reversed order: ";
    cin>>ele;
    ListNode *head2 = new ListNode(ele);
    ListNode *l2 = head2;
    for(int i=1;i<n2;i++){
        cin>>ele;
        l2->next = new ListNode(ele);
        l2 = l2->next;
    }

    ListNode *newHead = addTwoNumbers(head1, head2);
    ListNode *l3 = newHead;
    cout<<"Sum of two numbers are: ";
    while(l3){
        cout<<l3->val<<" ";
        l3 = l3->next;
    }
    cout<<endl;
}