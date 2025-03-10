#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
// BFS
// int isSumProperty(Node *root)
// {
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()){
//         Node *node = q.front();
//         q.pop();
//         int sum = 0;
//         if(node->left){
//             sum += node->left->data;
//             q.push(node->left);
//         }
//         if(node->right){
//             sum += node->right->data;
//             q.push(node->right);
//         }
//         if((node->left or node->right) and sum != node->data)
//             return false;
//     }
//     return true;
// }

// DFS
int isSumProperty(Node *root)
{
    if(root == nullptr or root->left == nullptr and root->right == nullptr)
        return true;
    int sum = 0;
    int left = isSumProperty(root->left);
    int right = isSumProperty(root->right);
    if(!(left and right))
        return false;
    if(root->left)
        sum += root->left->data;
    if(root->right)
        sum += root->right->data;
    return sum == root->data;
}
int main(){
    Node * root = new Node(10);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    if(isSumProperty(root)){
        cout<<"Satisified"<<endl;
    }
    else
        cout<<"Not satisfied"<<endl;
}