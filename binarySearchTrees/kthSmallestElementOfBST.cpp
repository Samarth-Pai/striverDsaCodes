#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// vector<int> inorderTraversal(TreeNode *root){
//     vector<int> inorder;
//     TreeNode *node = root;
//     while(node){
//         if(node->left == nullptr){
//             inorder.push_back(node->val);
//             node = node->right;
//         }
//         else{
//             TreeNode *rightmost = node->left;
//             while(rightmost->right and rightmost->right!=node)
//                 rightmost = rightmost->right;
//             if(rightmost->right){
//                 inorder.push_back(node->val);
//                 node = node->right;
//                 rightmost->right = nullptr;
//             }
//             else{
//                 rightmost->right = node;
//                 node = node->left;
//             }
//         }
//     }
//     return inorder;
// }

// Brute approach
// TC: O(N
// SC: O(1)
// int kthSmallest(TreeNode* root, int k) {
//     vector<int> inorder = inorderTraversal(root);
//     return inorder[k-1];
// }

void reverseInorder(TreeNode *node, int &k, int &kth){
    if(node == nullptr or k == 0)
        return;
    reverseInorder(node->left, k, kth);
    k--;
    if(k == 0){
        kth = node->val;
        return;
    }
    reverseInorder(node->right, k, kth);
}
// Optimal solution
// TC: O(height of tree)
// SC: O(1)
int kthSmallest(TreeNode *root, int k){
    int kth;
    reverseInorder(root, k, kth);
    return kth;
}
int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    cout<<"Kth smallest element: "<<kthSmallest(root, 3)<<endl;
}