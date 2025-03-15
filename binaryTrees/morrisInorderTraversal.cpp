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
// TC: O(N)
// SC: O(1)
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode *cur = root;
    while(cur!=nullptr){
        if(cur->left == nullptr){
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode *prev = cur->left;
            while(prev->right and prev->right!=cur){
                prev = prev->right;
            }
            if(prev->right == nullptr){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = nullptr;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    vector<int> res = inorderTraversal(root);
    cout<<"Inorder traversal: ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}