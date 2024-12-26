#include<iostream>
#include<map>
#include<vector>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode(int data1){
        val = data1;
        next = nullptr;
    }
};
ListNode *vectorTLL(vector<int> arr){
    ListNode *head = new ListNode(arr[0]);
    ListNode *ll = head;
    for(int i=1;i<arr.size();i++){
        ll->next = new ListNode(arr[i]);
        ll = ll->next;
    }
    return head;
}
// Brute approach
// TC: O(N1) + O(N2)
// SC: O(N1)
// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//     map<ListNode*, bool> mappa;
//     ListNode *l1 = headA;
//     ListNode *l2 = headB;
//     while(l1){
//         mappa[l1] = true;
//         l1 = l1->next;
//     }
//     while(l2){
//         if(mappa.find(l2)!=mappa.end()){
//             return l2;
//         }
//         l2 = l2->next;
//     }
//     return nullptr;
// }

ListNode *collisionPoint(ListNode *headA, ListNode *headB, int dist){
    ListNode *l1 = headA, *l2 = headB;
    while(dist){
        l2 = l2->next;
        dist--;
    }
    while(l1!=l2){
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1;
}

// Better approach
// TC: O(N1) + O(2N2)
// SC: O(1)
// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//     int n1 = 0, n2 = 0;
//     ListNode *l1 = headA, *l2 = headB;
//     while(l1){
//         n1++;
//         l1 = l1->next;
//     }
//     while(l2){
//         n2++;
//         l2 = l2->next;
//     }
//     if(n2>n1)
//         return collisionPoint(headA, headB, n2-n1);
//     else
//         return collisionPoint(headB, headA, n1-n2);
// }

// Optimal solution
// TC: O(N1 + N2)
// SC: O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *l1 = headA, *l2 = headB;
    while(l1!=l2){
        l1 = l1->next;
        l2 = l2->next;
        if(l1==l2) return l1;
        if(l1==nullptr) l1 = headB;
        if(l2==nullptr) l2 = headA;
    }
    return l1;
}

int main(){
    vector<int> a1 = {1, 2};
    vector<int> a2 = {3, 4, 5};
    vector<int> intrsctn = {6, 7, 8};
    ListNode *ll1 = vectorTLL(a1);
    ListNode *ll2 = vectorTLL(a2);
    ListNode *ll3 = vectorTLL(intrsctn);
    ListNode *temp1 = ll1;
    ListNode *temp2 = ll2;
    while(temp1->next){
        temp1 = temp1->next;
    }
    while(temp2->next){
        temp2 = temp2->next;
    }
    temp1->next = ll3;
    temp2->next = ll3;
    ListNode *intersectingNode = getIntersectionNode(ll1, ll2);
    ListNode *intHead = intersectingNode;
    cout<<"Intersection of linked list: ";
    while(intHead){
        cout<<intHead->val<<" ";
        intHead = intHead->next;
    }
    cout<<endl;
    return EXIT_SUCCESS;
}