#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute approach
// TC: O(N + NlogN + N )
// SC: O(N)
// ListNode* sortList(ListNode* head) {
//     vector<int> arr;
//     ListNode *temp = head;
//     while(temp){
//         arr.push_back(temp->val);
//         temp = temp->next;
//     }
//     sort(arr.begin(), arr.end());
//     temp = head;
//     int i = 0;
//     while(temp){
//         temp->val = arr[i];
//         i++;
//         temp = temp->next;
//     }
//     return head;
// }

ListNode *findMiddle(ListNode *head){
    if(head==nullptr or head->next==nullptr) return head;
    ListNode *slow = head, *fast = head;
    fast = fast->next->next;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *merge(ListNode *left, ListNode *right){
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;
    while(left and right){
        if(left->val < right->val){
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
    }
    if(left) temp->next = left;
    else temp->next = right;
    return dummyNode->next;
}

// Optimal solution: merge sort
// TC: O(logN * (N+N/2))
// SC: O(logN) for recursive stack space
ListNode *sortList(ListNode *head){
    if(head==nullptr or head->next == nullptr) return head;
    ListNode *middleNode = findMiddle(head);
    ListNode *right = middleNode->next;
    middleNode->next = nullptr;
    ListNode *left = head;
    left = sortList(left);
    right = sortList(right);
    return merge(left, right);
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

    ListNode *newHead = sortList(head);
    ListNode *ll2 = newHead;
    cout<<"Linked list after sorting the linked list: ";
    while(ll2){
        cout<<ll2->val<<" ";
        ll2 = ll2->next;
    }
    cout<<endl;
}