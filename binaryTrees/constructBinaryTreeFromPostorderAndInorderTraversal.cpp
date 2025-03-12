#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *build(vector<int> &inorder, vector<int> &postorder, map<int, int> &mappa, int postStart, int postEnd, int inStart, int inEnd){
    if(postEnd < postStart or inEnd < inStart)
        return nullptr;
    cout<<postStart<<' '<<postEnd<<' '<<inStart<<' '<<inEnd<<endl;
    TreeNode *node = new TreeNode(postorder[postEnd]);
    int ind = mappa[postorder[postEnd]];
    int nEle = ind - inStart;
    TreeNode *left = build(inorder, postorder, mappa, postStart, postStart + nEle - 1, inStart, ind - 1);
    TreeNode *right = build(inorder, postorder, mappa, postStart + nEle, postEnd - 1, ind + 1, inEnd);
    node->left = left;
    node->right = right;
    return node;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    map<int, int> mappa;
    int n = inorder.size();
    for(int i = 0;i<n;i++){
        mappa[inorder[i]] = i;
    }
    return build(inorder, postorder, mappa, 0, n-1, 0, n-1);
}
int main(){
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(inorder, postorder);
    cout<<root->val<<' '<<root->left->val<<' '<<root->right->val<<' '<<root->right->left->val<<' '<<root->right->right->val<<endl;
}