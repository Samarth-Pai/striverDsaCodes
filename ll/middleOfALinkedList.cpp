#include <iostream>
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
// TC: O(N + N/2)
// SC: O(1)
// ListNode* middleNode(ListNode* head) {
//     ListNode* temp = head;
//     int n = 0;
//     while(temp){
//         n++;
//         temp = temp->next;
//     }
//     int midIndex = n/2+1;
//     temp = head;
//     while(temp){
//         if(--midIndex == 0)
//             return temp;
//         temp = temp->next;
//     }
//     return nullptr;
// }

// Optimal solution: TortoiseHare Algorithm
// TC: O(N/2)
// SC: O(1)
ListNode* middleNode(ListNode* head){
    ListNode* slow = head, *fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

    ListNode* mid = middleNode(head);
    cout<<"Middle of the linked list is: "<<mid->val<<endl;
}