#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *helper(TreeNode *node){
    if(node->left == nullptr)
        return node->right;
    else if(node->right == nullptr)
        return node->left;
    TreeNode *rightmost = node->left;
    while(rightmost->right)
        rightmost = rightmost->right;
    rightmost->right = node->right;
    return node->left;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == nullptr)
        return root;
    else if(root->val == key)
        return helper(root);
    TreeNode *node = root;
    while(node){
        if(node->val > key){
            if(node->left and node->left->val == key){
                node->left = helper(node->left);
                break;
            }
            else
                node = node->left;
        }
        else{
            if(node->right and node->right->val == key){
                node->right = helper(node->right);
                break;
            }
            else
                node = node->right;
        }
    }
    return root;
}
string levelOrderTraversal(TreeNode *root){
    queue<TreeNode*> q;
    q.push(root);
    string s = "";
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        if(node){
            s.append(to_string(node->val) + ' ');
            q.push(node->left);
            q.push(node->right);
        }
        else{
            s.append("null ");
        }
    }
    return s;
}
int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout<<"Before: "<<levelOrderTraversal(root)<<endl;
    root = deleteNode(root, 3);
    cout<<"After: "<<levelOrderTraversal(root)<<endl;
}