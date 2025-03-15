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
int floor(Node* root, int input) {
    Node *node = root;
    int ans = -1;
    while(node){
        if(node->data <= input){
            ans = node->data;
            node = node->right;
        }
        else{
            node = node->left;
        }
    }
    return ans;
}
int main(){
    
    Node *root = newNode(2);
    root->right = newNode(81);
    root->right->left = newNode(42);
    root->right->right = newNode(87);
    root->right->right->right = newNode(90);
    root->right->left->right = newNode(66);
    root->right->left->right->left = newNode(45);
    cout<<"Floor of the BST: "<<floor(root, 87)<<endl;
}