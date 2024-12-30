#include<iostream>
#include<vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL){}
};

// Brute approach
// TC: O(N^2)
// SC: O(1)
// vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
//     vector<pair<int, int>> a;
//     Node *temp1 = head, *temp2;
//     while(temp1->next){
//         temp2 = temp1->next;
//         while(temp2 and temp1->data+temp2->data<=target){
//             if(temp1->data+temp2->data==target)
//                 a.push_back({temp1->data, temp2->data});
//             temp2 = temp2->next;
//         }
//         temp1 = temp1->next;
//     }
//     return a;
// }
Node *findTail(Node *head){
    Node *temp = head;
    while(temp->next) temp = temp->next;
    return temp;
}

// Optimal solution: two pointer approach
// TC: O(2N) one for finding tail and one for while loop
// SC: O(1)
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
    vector<pair<int, int>> a;
    Node *left = head, *right = findTail(head);
    while(left->data<right->data){
        if(left->data+right->data==target){
            a.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;    
        }
        else if(left->data+right->data<target){
            left = left->next;
        }
        else{
            right = right->prev;
        }
    }
    return a;
}

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

int main(){
    int ele, n, s;
    vector<int> arr;
    cout<<"Enter the linked list size: ";
    cin>>n;

    cout<<"Enter the linked list elements: ";
    for(int i =0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    Node *head = constructDLL(arr);
    cout<<"Enter the key: ";
    cin>>s;

    vector<pair<int, int>> a = findPairsWithGivenSum(head, s);
    cout<<"Pairs of given sum are: ";
    for(pair<int, int>p: a){
        cout<<"("<<p.first<<", "<<p.second<<") ";
    }
    cout<<endl;
}