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
int getDepth(TreeNode *root){
    if(root == nullptr)
        return 0;
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

// Brute approach
// TC: O(N^2)
// SC: O(N)
// bool isBalanced(TreeNode* root) {
//     if(root == nullptr)
//         return true;
//     int leftDepth = getDepth(root->left);
//     int rightDepth = getDepth(root->right);
//     if(abs(leftDepth - rightDepth) > 1)
//         return false;
//     return isBalanced(root->left) and isBalanced(root->right);
// }

int check(TreeNode *root){
    if(root == nullptr)
        return 0;
    int leftDepth = check(root->left);
    int rightDepth = check(root->right);
    if(leftDepth == -1 or rightDepth == -1)
        return -1;
    if(abs(leftDepth - rightDepth) > 1)
        return -1;
    return 1 + max(leftDepth, rightDepth);
}

// Optimal solution
// TC: O(N)
// SC: O(N)
bool isBalanced(TreeNode *root){
    return check(root)!=-1;
}

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout<<"Is it balanced? "<<isBalanced(root)<<endl;
}