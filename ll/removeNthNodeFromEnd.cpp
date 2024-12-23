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
// TC: O(n +N)
// SC: O(1)
// ListNode* removeNthFromEnd(ListNode* head, int n) {
//     int cnt = 0, res;
//     ListNode* ll = head;
//     while(ll){
//         cnt++;
//         ll = ll->next;
//     }
//     if(cnt==n){
//         ListNode* newHead = head->next;
//         free(head);
//         return newHead;
//     }
//     res = cnt - n;
//     ll = head;
//     while(ll){
//         res--;
//         if(res==0)
//             break;
//         ll = ll->next;
//     }
//     ListNode* delNode = ll->next;
//     ll->next = ll->next->next;
//     free(delNode);
//     return head;
// }

// Optimal solution
// TC: O(N)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *slow = head, *fast = head;
    for(int i = 0;i<n;i++){
        fast = fast->next;
    }
    if(fast==nullptr){
        ListNode* delNode = head    ;
        head = head->next;
        delete delNode;
        return head;
    }
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
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

    int N;
    cout<<"Enter n to delete nth node from the end of the linked list: ";
    cin>>N;

    ListNode *newHead = removeNthFromEnd(head, N);
    ListNode *ll2 = newHead;
    cout<<"New linked list: ";
    while(ll2){
        cout<<ll2->val<<" ";
        ll2 = ll2->next;
    }
    cout<<endl;
}