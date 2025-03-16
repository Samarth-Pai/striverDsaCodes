#include<iostream>
#include<vector>
#include<algorithm>
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
TreeNode* construct(vector<int> &preorder, map<int, int> &inmap, int preStart, int preEnd, int inStart, int inEnd){
    if(preStart > preEnd)
        return  nullptr;
    TreeNode *node = new TreeNode(preorder[preStart]);
    int ind = inmap[node->val];
    node->left = construct(preorder, inmap, preStart+1, preStart+ind-inStart, inStart, ind+1);
    node->right = construct(preorder, inmap, preStart+ind+1-inStart, preEnd, ind+1, inEnd);
    return node;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    vector<int> inorder(preorder);
    sort(inorder.begin(), inorder.end());
    int n = preorder.size();
    map<int, int> inmap;
    for(int i = 0;i<inorder.size();i++){
        inmap[inorder[i]] = i;
    }
    return construct(preorder, inmap, 0, n-1, 0, n-1);
}
int main(){
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode *root = bstFromPreorder(preorder);
    cout<<root->val<<' '<<root->left->val<<' '<<root->right->val<<' '<<root->left->left->val<<' '<<root->left->right->val<<' '<<root->right->right->val<<endl;
}