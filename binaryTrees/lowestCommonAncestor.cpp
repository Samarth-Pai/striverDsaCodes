#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
typedef pair<bool, bool> pbb;
void findn(TreeNode *root, TreeNode *p, TreeNode *q, pbb &found){
    if(root == nullptr)
        return;
    findn(root->left, p, q, found);
    findn(root->right, p, q, found);
    if(root == p)
        found.first = true;
    if(root == q)
        found.second = true;
}
// Brute approach
// TC: O(N^2)
// SC: O(2N)
// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     queue<TreeNode*> qu;
//     qu.push(root);
//     TreeNode *ans = nullptr;
//     while(!qu.empty()){
//         TreeNode * node = qu.front();
//         qu.pop();
//         pbb found;
//         findn(node, p, q, found);
//         if(found.first and found.second){
//             ans = node;
//         }
//         if(node->left)
//             qu.push(node->left);
//         if(node->right)
//             qu.push(node->right);
//     }
//     return ans;
// }

// Optimal solution:
// TC: O(N)
// SC: O(N) auxilliary space
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr or root == p or root == q)
        return root;
    TreeNode *l = lowestCommonAncestor(root->left, p, q);
    TreeNode *r = lowestCommonAncestor(root->right, p, q);
    if(l == nullptr)
        return r;
    else if(r == nullptr)
        return l;
    else
        return root;
}
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode *ans = lowestCommonAncestor(root, root->left, root->right);
    cout<<"Answer: "<<ans->val<<endl;
}