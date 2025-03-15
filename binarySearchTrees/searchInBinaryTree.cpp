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
// TC: O(logN)
// SC: O(1)
TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode *cur = root;
    while(cur!=nullptr){
        if(cur->val == val)
            return cur;
        else if(cur->val > val)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return nullptr;
}
int main(){
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    TreeNode *res = searchBST(root,2);
    if(res)
        cout<<"Node found!"<<endl;
    else
        cout<<"Node not found"<<endl;
}