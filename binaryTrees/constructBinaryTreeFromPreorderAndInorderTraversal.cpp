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
TreeNode *build(vector<int> &preoder, vector<int> &inorder, map<int, int> &mappa, int preStart, int preEnd, int inStart, int inEnd){
    if(preEnd < preStart)
        return nullptr;
    int ind = mappa[preoder[preStart]];
    TreeNode *left = build(preoder, inorder, mappa, preStart+1, preStart + ind - inStart, inStart, ind + 1);
    TreeNode *right = build(preoder, inorder, mappa, preStart + ind + 1 - inStart, preEnd, ind+1, inEnd);
    TreeNode *node = new TreeNode(preoder[preStart]);
    node->left = left;
    node->right = right;
    return node;
}

// TC: O(N)
// SC: O(N)
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> mappa;
    for(int i = 0;i<preorder.size();i++){
        mappa[inorder[i]] = i;
    }
    return build(preorder, inorder, mappa, 0, inorder.size()-1, 0, inorder.size() - 1);
}
int main(){
    vector<int> preoder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(preoder, inorder);
    cout<<root->val<<' '<<root->left->val<<' '<<root->right->val<<' '<<root->right->left->val<<' '<<root->right->right->val<<endl;
}