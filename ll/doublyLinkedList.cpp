#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    // Node(int data1, Node* next1, Node* prev1){
    //     data = data1;
    //     prev = prev1;
    //     next = next1;
    // }
    Node(int data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
    Node(){
        data = 0;
        prev = nullptr;
        next = nullptr;
    }
};
// Node* constructDLL(vector<int>& arr) {
//     Node* head = new Node(arr[0]);
//     Node* prevNode = head;
//     for(int i = 1;i<arr.size();i++){
//         Node* temp = new Node(arr[i], nullptr, prevNode);
//         prevNode->next = temp;
//         prevNode = temp;
//     }
//     return head;
// }
Node* constructDLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prevNode = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        temp->prev = prevNode;
        prevNode->next = temp;
        prevNode = temp;
    }
    return head;
}

void printLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    int ele, n;
    vector<int> arr;
    cout<<"Enter size of array: ";
    cin>>n;

    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    Node* head = constructDLL(arr);
    cout<<"Elements in double linked list are ";
    printLL(head);
    cout<<endl;
}