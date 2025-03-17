#include<iostream>
#include<vector>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};
vector<int> inorderTraversal(Node *root){
    vector<int> inorder;
    Node *node = root;
    while(node){
        if(node->left == nullptr){
            inorder.push_back(node->data);
            node = node->right;
        }
        else{
            Node *rightmost = node->left;
            while(rightmost->right and rightmost->right!=node)
                rightmost = rightmost->right;
            if(rightmost->right == nullptr){
                rightmost->right = node;
                node = node->left;
            }
            else{
                inorder.push_back(node->data);
                rightmost->right = nullptr;
                node = node->right;
            }
        }
    }
    return inorder;
}
vector<int> merge(Node *root1, Node *root2) {
    vector<int> in1 = inorderTraversal(root1);
    vector<int> in2 = inorderTraversal(root2);
    vector<int> res;
    int i = 0, j = 0;
    while(i<in1.size() and j<in2.size()){
        if(in1[i] < in2[j]){
            res.push_back(in1[i]);
            i++;
        }
        else{
            res.push_back(in2[j]);
            j++;
        }
    }
    while(i<in1.size()){
        res.push_back(in1[i]);
        i++;
    }
    while(j<in2.size()){
        res.push_back(in2[j]);
        j++;
    }
    return res;
}
int main(){
    Node *r1 = new Node(5);
    r1->left = new Node(3);
    r1->right = new Node(6);
    r1->left->left = new Node(2);
    r1->left->right = new Node(4);
    Node *r2 = new Node(2);
    r2->left = new Node(1);
    r2->right = new Node(3);
    r2->right->right = new Node(7);
    r2->right->right->left = new Node(6);
    vector<int> mer = merge(r1, r2);
    for(int i: mer)
        cout<<i<<' ';
    cout<<endl;
}