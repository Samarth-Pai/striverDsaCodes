#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
  
    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool isLeaf(Node *root){
    return root->left == nullptr and root->right == nullptr;
}
void leftBoundaryTraversal(Node *root, vector<int> &res){
    Node *node = root->left;
    while(node){
        if(!isLeaf(node))
            res.push_back(node->data);
        if(node->left)
            node = node->left;
        else
            node = node->right;
    }
}
void leafTraversal(Node *root, vector<int> &res){
    if(root == nullptr)
        return;
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    leafTraversal(root->left, res);
    leafTraversal(root->right, res);
}
void rightBoundaryTraversal(Node *root, vector<int> &res){
    Node *node = root->right;
    stack<int>st;
    while(node){
        if(!isLeaf(node))
            st.push(node->data);
        if(node->right)
            node = node->right;
        else
            node = node->left;
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
}
vector<int> boundaryTraversal(Node *root) {
    vector<int> res;
    if(root == nullptr)
        return res;
    if(!isLeaf(root))
        res.push_back(root->data);
    leftBoundaryTraversal(root, res);
    leafTraversal(root, res);
    rightBoundaryTraversal(root, res);
    return res;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> arr = boundaryTraversal(root);
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}