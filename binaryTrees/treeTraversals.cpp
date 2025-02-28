#include<iostream>
#include<vector>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
void traverseInorder(TreeNode *root, vector<int> &res){
    if(root == nullptr)
        return;
    traverseInorder(root->left, res);
    res.push_back(root->data);
    traverseInorder(root->right, res);
}
void traversePreorder(TreeNode *root, vector<int> &res){
    if(root == nullptr)
        return;
    res.push_back(root->data);
    traversePreorder(root->left, res);
    traversePreorder(root->right, res);
}
void traversePostorder(TreeNode *root, vector<int> &res){
    if(root == nullptr)
        return;
    traversePostorder(root->left, res);
    traversePostorder(root->right, res);
    res.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> inorder, preorder, postorder;
    traverseInorder(root, inorder);
    traversePreorder(root, preorder);
    traversePostorder(root, postorder);
    return {inorder, preorder, postorder};
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);
    vector<vector<int>> ans = getTreeTraversal(root);
    cout<<"Inorder traversal: ";
    for(int i: ans[0])
        cout<<i<<" ";
    cout<<endl<<"Pre-order traversal: ";
    for(int i: ans[1])
        cout<<i<<" ";
    cout<<endl<<"Post-order traversal: ";
    for(int i: ans[2])
        cout<<i<<" ";
    cout<<endl;
}