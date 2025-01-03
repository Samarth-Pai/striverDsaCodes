#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *constructLL(vector<int> arr){
    Node *head = new Node(-1);
    Node *ll = head;
    for(int ele: arr){
        ll->bottom = new Node(ele);
        ll = ll->bottom;
    }
    return head->bottom;
}

// Brute force
// TC: O(N*M)*2 + O(X*logX) where X is N*M
// SC: O(N*M)*2
// Node *flatten(Node *head) {
//     vector<int> a;
//     Node *ll = head, *bottomLL;
//     while(ll){
//         a.push_back(ll->data);
//         bottomLL = ll->bottom;
//         while(bottomLL){
//             a.push_back(bottomLL->data);
//             bottomLL = bottomLL->bottom;
//         }
//         ll = ll->next;
//     }
//     sort(a.begin(), a.end());
//     return constructLL(a);
// }


// TC: O(N1 + N2)
Node *merege2lists(Node *list1, Node *list2){
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while(list1 and list2){
        if(list1->data<list2->data){
            res->bottom = list1;
            res = res->bottom;
            list1 = list1->bottom;
        }
        else{
            res->bottom = list2;
            res = res->bottom;
            list2 = list2->bottom;
        }
        res->next = nullptr;
    }
    if(list1) res->bottom = list1;
    else res->bottom = list2;
    if(dummyNode->bottom) dummyNode->bottom->next = nullptr;
    return dummyNode->bottom;
}

// Optimal solution
// TC: N*O(2M) = O(2NM)
// SC: O(N)
Node *flatten(Node *head) {
    if(head==nullptr or head->next==nullptr) return head;
    Node *mergedHead = flatten(head->next);
    return merege2lists(head, mergedHead);      
}
int main(){
    int m, n, ele;
    Node *head = new Node(-1);
    Node *ll = head;
    cout<<"Enter the no. of parent nodes: ";
    cin>>n;
    for(int i = 0;i<n;i++){
        cout<<"Enter the value of parent node: ";
        cin>>ele;
        ll->next = new Node(ele);
        ll = ll->next;
        Node *bottomLL = ll;
        cout<<"Enter the no. of child nodes: ";
        cin>>m;
        if(m) cout<<"Enter the child nodes: ";
        for(int j=0;j<m;j++){
            cin>>ele;
            bottomLL->bottom = new Node(ele);
            bottomLL = bottomLL->bottom;
        }
    }
    head = head->next;
    ll = head;
    cout<<endl<<"Original ll:\n";
    while(ll){
        cout<<ll->data<<": ";
        Node *btl = ll->bottom;
        if(btl==nullptr) cout<<"null";
        while(btl){
            cout<<btl->data<<" ";
            btl = btl->bottom;
        }
        ll = ll->next;
        cout<<endl;
    }
    cout<<endl<<"Flattened linked list: ";
    Node *newHead = flatten(head);
    Node *ll2 = newHead;
    while(ll2){
        cout<<ll2->data<<" ";
        ll2 = ll2->bottom;
    }
    cout<<endl;
}