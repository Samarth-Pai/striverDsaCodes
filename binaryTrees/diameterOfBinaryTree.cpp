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

// int diameter = 0;
// int findDepth(TreeNode *root){
//     if(root == nullptr)
//         return 0;
//     int leftDepth = findDepth(root->left);
//     int rightDepth = findDepth(root->right);
//     diameter = max(diameter, leftDepth + rightDepth);
//     return 1 + max(leftDepth, rightDepth);
// }
// Brute approach
// TC: O(N^2)
// SC: O(N)
// int diameterOfBinaryTree(TreeNode* root) {
//     findDepth(root);
//     return diameter;
// }


int findDepth(TreeNode *root, int &dia){
    if(root == nullptr)
        return 0;
    int lh = findDepth(root->left, dia);
    int rh = findDepth(root->right, dia);
    dia = max(dia, lh + rh);
    return 1 + max(lh, rh);
}
// Optimal solution
// TC: O(N)
// SC: O(1)
int diameterOfBinaryTree(TreeNode* root) {
    int dia = 0;
    findDepth(root, dia);
    return dia;
}

int 
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout<<"Diameter of the binary tree: "<<diameterOfBinaryTree(root)<<endl;
}