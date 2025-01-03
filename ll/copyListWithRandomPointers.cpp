#include<iostream>
#include<map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Brute approach
// TC: O(2N) assuming map works with O(1)
// SC: O(N) + O(N)(which is needed to return)
// Node* copyRandomList(Node* head) {
//     map<Node*, Node*> mappa;
//     Node *temp = head;
//     while(temp){
//         Node *newNode = new Node(temp->val);
//         mappa[temp] = newNode;
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp){
//         Node *copyNode = mappa[temp];
//         copyNode->next = mappa[temp->next];
//         copyNode->random = mappa[temp->random];
//         temp = temp->next;
//     }
//     return mappa[head];
// }

// Optimal solution
// TC: O(3N)
// SC: O(N) to create new list
Node *copyRandomList(Node *head){
    // Insert copy nodes in between
    Node *temp = head;
    while(temp){
        Node *newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
    // Connect random pointers
    temp = head;
    while(temp){
        Node *copyNode = temp->next;
        if(temp->random) copyNode->random = temp->random->next;
        else copyNode->random = nullptr;
        temp = temp->next->next;
    }
    // Connect next pointers
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    temp = head;
    while(temp){
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dummyNode->next;
}
int main(){
    Node *l1 = new Node(7);
    Node *head = l1;
    Node *l2 = new Node(13);
    l1->next = l2;
    Node *l3 = new Node(11);
    l2->next = l3;
    Node *l4 = new Node(10);
    l3->next = l4;
    Node *l5 = new Node(1);
    l4->next = l5;
    l2->random = l1;
    l3->random = l5;
    l4->random = l3;
    l5->random = l1;
    Node *newHead = copyRandomList(head);
    Node *ll = newHead;
    cout<<"Copied linked list: ";
    while(ll){
        cout<<ll->val<<" ";
        ll = ll->next;
    }
    cout<<endl;
}