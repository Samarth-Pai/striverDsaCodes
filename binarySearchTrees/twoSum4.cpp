#include<iostream>
#include<map>
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
    vector<int> inorder;
    TreeNode *node = root;
    while(node){
        if(node->left == nullptr){
            inorder.push_back(node->val);
            node = node->right;
        }
        else{
            TreeNode *rightmost = node->left;
            while(rightmost->right and rightmost->right!=node)
                rightmost = rightmost->right;
            if(rightmost->right == nullptr){
                rightmost->right = node;
                node = node->left;
            }
            else{
                inorder.push_back(node->val);
                rightmost->right = nullptr;
                node = node->right;
            }
        }
    }
    return inorder;
}
bool findTarget(TreeNode* root, int k) {
    map<int, int> mappa;
    TreeNode *node = root;
    vector<int> inorder = inorderTraversal(root);
    int i = 0, j = inorder.size()-1;
    while(i < j){
        int sum = inorder[i] + inorder[j];
        if(sum > k)
            j--;
        else if(sum < k)
            i++;
        else{
            return true;
        }
    }
    return false;
}
int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    cout<<"Two sum exists: "<<findTarget(root, 9)<<endl;
}