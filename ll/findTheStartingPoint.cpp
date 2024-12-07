#include<iostream>
#include<map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// Brute force: hashing
// TC: O(N 2logN)
// SC: O(N)
// ListNode *detectCycle(ListNode *head) {
//     map<ListNode*, int> mpp;
//     ListNode* temp = head;
//     while(temp){
//         if(mpp.find(temp)!=mpp.end())
//             return temp;
//         mpp[temp]++;
//         temp = temp->next;
//     }
//     return nullptr;
// }

// Tortoise Hare algorithm
// TC: O(N)
// SC: O(1)
ListNode *detectCycle(ListNode* head){
    ListNode *slow = head, *fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return  slow;
        }
    }
    return nullptr;
}
int main(){
    ListNode* head = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    head->next = n2;
    ListNode* n3 = new ListNode(0);
    n2->next = n3;
    ListNode* n4 = new ListNode(-4);
    n3->next = n4;
    n4->next = n2;

    cout<<"Node connecting to the loop "<<detectCycle(head)->val<<endl;
    return 0;
}

