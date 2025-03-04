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
// TC: O(N)
// SC: O(1)
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr or q == nullptr)
        return p == nullptr and q == nullptr;
    if(p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
}
int main(){
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    if(isSameTree(root1, root2))
        cout<<"Same trees"<<endl;
    else
        cout<<"Not same"<<endl;
}