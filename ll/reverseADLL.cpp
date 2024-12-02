#include<iostream>
#include<stack>
using namespace std;
class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

// Brute approach: using stack
// TC: O(2N)
// SC: O(N)
// Node* reverseDLL(Node* head)
// {
//     Node* temp = head;
//     stack<int> st;
//     while(temp){
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     Node* temp2 = head;
//     while(temp2){
//         temp2->data = st.top();
//         st.pop();
//         temp2 = temp2->next;
//     }
//     return head;
// }

// Optimal solution
// TC: O(N)
// SC: O(1)
Node* reverseDLL(Node* head){
    if(head == nullptr or head->next == nullptr) return head;
    Node* last;
    Node* current = head;
    while(current){
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }
    return last->prev;
}

int main(){
    int ele, n;
    cout<<"Enter the linked list size: ";
    cin>>n;

    cout<<"Enter the linked list elements: ";
    cin>>ele;
    Node* head = new Node(ele);
    Node* dll = head;
    for(int i = 1;i<n;i++){
        cin>>ele;
        Node* temp = new Node(ele, nullptr, dll);
        dll->next = temp;
        dll = temp;
    }

    head = reverseDLL(head);
    Node* dll2 = head;
    cout<<"Linked list after reversing: ";
    while(dll2){
        cout<<dll2->data<<" ";
        dll2 = dll2->next;
    }
    cout<<endl;

    return EXIT_SUCCESS;
}