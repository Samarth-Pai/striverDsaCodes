#include<iostream>
#include<stack>
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
// SC: O(2N)
vector<int> postorderTraversal(TreeNode* root) {
    if(root == nullptr)
        return {};
    stack<TreeNode*> st1;
    stack<int> st2;
    vector<int> res;
    st1.push(root);
    while(!st1.empty()){
        TreeNode *node = st1.top();
        st1.pop();
        st2.push(node->val);
        if(node->left)
            st1.push(node->left);
        if(node->right)
            st1.push(node->right);
    }
    while(!st2.empty()){
        res.push_back(st2.top());
        st2.pop();
    }
    return res;
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
    vector<int> res = postorderTraversal(root);
    cout<<"Postorder traversal: ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}