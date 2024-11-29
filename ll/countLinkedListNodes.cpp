#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int getCount(Node* head) {
     Node *temp = head;
     int cnt = 0;
     while(temp){
         cnt++;
         temp = temp->next;
    }
    return cnt;
}
int main(){
    int ele, n, count;
    cout<<"Enter the linked list size: ";
    cin>>n;

    cout<<"Enter the linked list elements: ";
    cin>>ele;
    Node* head = new Node(ele);
    Node* ll = head;
    for(int i = 1;i<n;i++){
        cin>>ele;
        ll->next = new Node(ele);
        ll = ll->next;
    }

    count  = getCount(head);
    cout<<"No. of nodes in the linked list is "<<count<<endl;
}