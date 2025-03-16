#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> inorderTraversal(TreeNode *root){
    TreeNode *node = root;
    vector<int> inorder;
    while(node){
        if(node->left == nullptr){
            inorder.push_back(node->val);
            node = node->right;
        }
        else{
            TreeNode *prev = node->left;
            while(prev->right and prev->right!=node)
                prev = prev->right;
            if(prev->right){
                inorder.push_back(node->val);
                prev->right = nullptr;
                node = node->right;
            }
            else{
                prev->right = node;
                node = node->left;
            }
        }
    }
    return inorder;
}
// TC: O(N)
// SC: O(N)
bool isValidBST(TreeNode* root) {
    vector<int> inorder = inorderTraversal(root);
    for(int i = 1;i<inorder.size();i++){
        if(inorder[i] <= inorder[i-1])
            return false;
    }
    return true;
}
int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    if(isValidBST(root))
        cout<<"It is BST"<<endl;
    else
        cout<<"It is not BST"<<endl;
}