#include<iostream>
using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

// TC: O(2h)
// SC: O(1)
// void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
// {
//     Node *node = root;
//     while(node){
//         if(node->key < key){
//             pre = node;
//             node = node->right;
//         }
//         else{
//             node = node->left;
//         }
//     }
//     node = root;
//     while(node){
//         if(node->key > key){
//             suc = node;
//             node = node->left;
//         }
//         else{
//             node = node->right;
//         }
//     }
// }

Node *rightMost(Node *node){
    while(node->right)
        node = node->right;
    return node;
}
Node *leftMost(Node *node){
    while(node->left)
        node = node->left;
    return node;
}
// TC: O(h)
// SC: O(1)
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node *node = root;
    while(node){
        if(node->key < key){
            pre = node;
            node = node->right;
        }
        else if(node->key > key){
            suc = node;
            node = node->left;
        }
        else{
            if(node->left)
                pre = rightMost(node->left);
            if(node->right)
                suc = leftMost(node->right);
            break;
        }
    }
}
int main(){
    Node *root = new Node(8);
    root->left = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right = new Node(9);
    root->right->right = new Node(10);
    Node *pre = new Node(-1), *suc = new Node(-1);
    findPreSuc(root, pre, suc, 8);
    cout<<"Predeccesor: "<<pre->key<<endl;
    cout<<"Successor: "<<suc->key<<endl;
}