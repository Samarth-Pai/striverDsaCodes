#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// TC: O(N)
// SC: O(N) auxiliary space
void flatten(TreeNode *node){
    if(node == nullptr)
        return;
    flatten(node->left);
    flatten(node->right);
    if(node->left and node->right){
        TreeNode *rightNode = node->right;
        TreeNode *rightmost = node->left;
        while(rightmost->right)
            rightmost = rightmost->right;
        node->right = node->left;
        rightmost->right = rightNode;
        node->left = nullptr;
    }
    else if(node->left){
        node->right = node->left;
        node->left = nullptr;
    }
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    flatten(root);
    TreeNode *node = root;
    cout<<"Linked list: ";
    while(node){
        cout<<node->val<<" ";
        node = node->right;
    }
    cout<<endl;
}