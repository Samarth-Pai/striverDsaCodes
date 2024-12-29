#include<iostream>
#include<vector>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};
Node* constructDLL(vector<int> arr){
    int n = arr.size();
    Node *head = new Node(arr[0]);
    Node *prevNode = head;
    for(int i=1;i<n;i++){
        Node *temp = new Node(arr[i]);
        temp->prev = prevNode;
        prevNode->next = temp;
        prevNode = temp;
    }
    return head;
}
void deleteAllOccurOfX(struct Node** head, int x) {
    Node *temp = *head;
    Node *newNode, *prevNode;
    while(temp){
        if(temp->data==x){
            if(temp==*head) *head = temp->next;
            newNode = temp->next;
            prevNode = temp->prev;
            if(newNode) newNode->prev = prevNode;
            if(prevNode) prevNode->next = newNode;
            // delete temp;
            temp = newNode;
        }
        else
            temp = temp->next;
    }
}

int main(){
    vector<int> arr;
    int n, key, ele;
    cout<<"Enter the linked list size: ";
    cin>>n;

    cout<<"Enter the linked list elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    Node *head = constructDLL(arr);
    
    cout<<"Enter a key to delete all its occurances: ";
    cin>>key;

    deleteAllOccurOfX(&head, key);
    cout<<"New linked list: ";
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}