#include<iostream>
#include<map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute approach
// TC: O(N * 2logN)
// SC: O(N)
// bool hasCycle(ListNode *head) {
//     map<ListNode*, bool> mpp;
//     ListNode* temp = head;
//     while(temp){
//         if(mpp.find(temp)!=mpp.end())
//             return true;
//         mpp[temp] = true;
//         temp = temp->next;
//     }
//     return false;
// }

// Optimal solution: TortoiseHare algorithm
// TC: O(N)
// SC: O(1)
bool hasCycle(ListNode* head){
    if(head==nullptr) return false;
    ListNode *slow = head, *fast = head->next;
    while(fast and fast->next){
        if(slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
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

    cout<<"Linked list has a cycle? "<<hasCycle(head)<<endl;

}