#include<iostream>
#include<vector>
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

bool searchKey(int n, struct Node* head, int key) {
    Node* temp = head;
    while(temp){
        if(temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    int n, ele;
    cout<<"Enter linked list size: ";
    cin>>n;

    cout<<"Enter linked list elements: ";
    cin>>ele;
    Node* head = new Node(ele);
    Node* ll = head;
    for(int i = 1;i<n;i++){
        cin>>ele;
        Node* temp = new Node(ele);
        ll->next = temp;
        ll = temp;
    }

    cout<<"Enter the search element: ";
    cin>>ele;

    bool isPresent = searchKey(n, head, ele);
    if(isPresent)
        cout<<ele<<" found in the linked list"<<endl;
    else
        cout<<ele<<" not found"<<endl;
    return 0;
}