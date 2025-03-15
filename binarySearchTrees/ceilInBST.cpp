#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
// TC: o(logN)
// SC: O(1)
int findCeil(Node* root, int x) {
    if (root == NULL) return -1;
    Node *node = root;
    int ans = -1;
    while(node){
        if(node->data < x)
            node = node->right;
        else{
            ans = node->data;
            node = node->left;
        }
    }
    return ans;
}
int main(){
    Node *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(11);
    root->left->left = newNode(4);
    root->left->right = newNode(7);
    root->left->right->right = newNode(8);
    cout<<"Ceil of the BST: "<<findCeil(root, 6)<<endl;
}