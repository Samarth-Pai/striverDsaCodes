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
int minValue(Node* root) {
    if(root == nullptr)
        return 0;
    Node *node = root;
    while(node->left)
        node = node->left;
    return node->data;
}
int main(){
    Node *root = newNode(5);
    root->left = newNode(4);
    root->left->left = newNode(3);
    root->left->left = newNode(1);
    root->right = newNode(6);
    root->right = newNode(7);
    cout<<"Minimum element: "<<minValue(root)<<endl;
}