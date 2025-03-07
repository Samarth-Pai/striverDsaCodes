#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool traverse(TreeNode *leftnode, TreeNode *rightnode){
    if(leftnode == nullptr or rightnode == nullptr)
        return leftnode == rightnode;
    if(leftnode->val != rightnode->val)
        return false;
    return traverse(leftnode->left, rightnode->right)
    and traverse(leftnode->right, rightnode->left);
}
bool isSymmetric(TreeNode* root) {
    return traverse(root->left, root->right);
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    bool ans = isSymmetric(root);
    if(ans)
        cout<<"Given tree is symmetric"<<endl;
    else
        cout<<"Given tree in asymmetric"<<endl;
}