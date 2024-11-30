#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
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

Node* deleteHead(Node* head){
    Node* prevNode = head;
    head = head->next;
    head->prev = nullptr;
    prevNode->next = nullptr;
    free(prevNode);
    return head;
}
Node* deleteTail(Node* head){
    Node* temp = head;
    while(temp->next)
        temp = temp->next;
    Node* prevNode = temp->prev;
    prevNode->next = nullptr;
    temp->prev = nullptr;
    free(temp);
    return head;
}

// 1-based indexing pos
Node* deleteNode(Node* head, int pos){
    if(head == nullptr) return nullptr;
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt == pos) break;
        temp = temp->next;
    }
    Node *prevNode = temp->prev;
    Node *frontNode = temp->next;
    if(prevNode==nullptr and frontNode == nullptr){
        free(temp);
        return nullptr;
    }
    else if(prevNode==nullptr){
        frontNode->prev = nullptr;
        temp->next = nullptr;
        free(temp);
        return frontNode;
    }

    else if(frontNode==nullptr){
        prevNode->next = nullptr;
        temp->prev = nullptr;
        free(temp);
        return head;
    }
    else{
        prevNode->next = frontNode;
        frontNode->prev = prevNode;
        temp->prev = nullptr;
        temp->next = nullptr;
        free(temp);
        return head;
    }
}

void deleteParticularNode(Node* node){
    Node* prevNode = node->prev;
    Node* frontNode = node->next;
    if(frontNode == nullptr){
        prevNode->next = nullptr;
        node->prev = nullptr;
        free(node);
        return;
    }
    prevNode->next = frontNode;
    frontNode->prev = prevNode;
    
    node->prev = nullptr;
    node->next = nullptr;
}


int main(){
    int ele, n, k;
    vector<int> arr;
    cout<<"Enter size of array: ";
    cin>>n;

    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    Node* head = constructDLL(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    
    cout<<"Enter the position at which the node is to be deleted: ";
    cin>>k;
    head = deleteNode(head, k);
    cout<<"Elements in double linked list are ";
    printLL(head);
    cout<<endl;
}