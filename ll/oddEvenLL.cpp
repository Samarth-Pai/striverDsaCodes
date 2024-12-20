#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute appraoch
// TC: O(2N)
// SC: O(N)
// ListNode* oddEvenList(ListNode* head) {
//     if(head==nullptr or head->next==nullptr) return head;
//     vector<int>arr;
//     ListNode* temp = head;
//     while(temp and temp->next){
//         arr.push_back(temp->val);
//         temp = temp->next->next;
//     }
//     if(temp) arr.push_back(temp->val);

//     temp = head->next;
//     while(temp and temp->next){
//         arr.push_back(temp->val);
//         temp = temp->next->next;
//     }
//     if(temp) arr.push_back(temp->val);
    

//     temp = head;
//     int i = 0;
//     while(temp){
//         temp->val = arr[i];
//         i++;
//         temp = temp->next;
//     }
//     return head;
// }

// Brute approach
// TC: O(N)
// SC: O(1)
ListNode* oddEvenList(ListNode* head) {
    if(head==nullptr or head->next==nullptr) return head;
    ListNode *odd = head, *even = head->next, *evenHead = head->next;
    while(even and even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;        
    return head;
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

    cout<<"Linked list after segragating even and odd nodes: ";
    ListNode* newHead = oddEvenList(head);
    while(newHead){
        cout<<newHead->val<<" ";
        newHead = newHead->next;
    }
    cout<<endl;
}