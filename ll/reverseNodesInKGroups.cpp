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
    while(temp and k>1){
        k--;
        temp = temp->next;
    }
    return temp;
}

void reverseLL(ListNode *head){
    ListNode *temp = head;
    ListNode *nextNode, *prevNode = nullptr;
    while(temp){
        nextNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
    }
}

// TC: O(2N)
// SC: O(1)
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *prevNode = nullptr, *kthNode, *nextNode;
    ListNode *temp = head;
    while(temp){
        kthNode = findKthNode(temp, k);
        if(kthNode==nullptr){
            if(prevNode) prevNode->next = temp;
            break;
        }
        nextNode = kthNode->next;
        kthNode->next = nullptr;
        reverseLL(temp);
        if(temp==head)
            head = kthNode;
        else
            prevNode->next = kthNode;
        prevNode = temp;
        temp = nextNode;
    }
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
    cout<<"Enter k: ";
    cin>>k;

    ListNode *newHead = reverseKGroup(head, k);
    ll = newHead;
    cout<<"New linked list: ";
    while(ll){
        cout<<ll->val<<" ";
        ll = ll->next;
    }
    cout<<endl;
    return EXIT_SUCCESS;
}