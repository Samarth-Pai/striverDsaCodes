#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }      
};
Node *constructDLL(vector<int> a){
    Node* head = new Node(a[0]);
    Node *prevNode = head;
    Node *temp = head->next;
    for(int i=1;i<a.size();i++){
        Node *temp = new Node(a[i]);
        prevNode->next = temp;
        temp->prev = prevNode;
        prevNode = temp;
    }
    return head;
}
// TC: O(N)
// SC: O(1)
Node * removeDuplicates(Node *head)
{
    Node *temp = head, *nextNode = head->next;
    while(temp and temp->next){
        nextNode = temp->next;
        while(nextNode and nextNode->data==temp->data){
            Node *duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;
        temp = temp->next;
    }
    return head;
}
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter linked list size: ";
    cin>>n;

    cout<<"Enter the linked list elements in sorted order with some repeating: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    Node *head = constructDLL(arr);
    Node *newHead = removeDuplicates(head);
    Node *ll = newHead;
    cout<<"New linked list: ";
    while(ll){
        cout<<ll->data<<" ";
        ll = ll->next;
    }
    cout<<endl;
}