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
// SC: O(N)
vector<int> inorderTraversal(TreeNode* root) {
    if(root == nullptr)
        return {};
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode *node = root;
    while(true){
        if(node){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            res.push_back(node->val);
            node = node->right;
        }
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
    vector<int> res = inorderTraversal(root);
    cout<<"Inorder traversal: ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}