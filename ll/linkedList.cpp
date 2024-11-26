#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* constructLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

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
    // Node y = Node(2, nullptr); 
    Node *y = new Node(2);
    cout<<"Data inside head is "<<y->data<<endl;

    int n, ele;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;

    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    // Node* ll = constructLL(arr); Rule no.1: never ever tamper the head
    Node* head = constructLL(arr);
    Node* ll = head;
    cout<<"Elements in the linked list are: ";
    while(ll != nullptr){
        cout<<ll->data<<" ";
        ll = ll->next;
    }

    cout<<endl<<"Length of the linked list is "<<getCount(head)<<endl;
    cout<<endl;
    return 0;
}