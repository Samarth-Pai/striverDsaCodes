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

// Striver's solution
// TreeNode* insertIntoBST(TreeNode* root, int val) {
//     if(root == nullptr)
//             return new TreeNode(val);
//     TreeNode *node = root;
//     while(node){
//         if(node->val < val){
//             if(node->right)
//                 node = node->right;
//             else{
//                 node->right = new TreeNode(val);
//                 break;
//             }
//         }
//         else{
//             if(node->left)
//                 node = node->left;
//             else{
//                 node->left = new TreeNode(val);
//                 break;
//             }
//         }
//     }
//     return root;
// }

// My solution
TreeNode *insertIntoBST(TreeNode *root, int val){
    TreeNode *lastnode = nullptr;
    TreeNode *node = root;
    while(node){
        lastnode = node;
        if(node->val > val)
            node = node->left;
        else
            node = node->right;
    }
    if(lastnode->val > val)
        lastnode->left = new TreeNode(val);
    else
        lastnode->right = new TreeNode(val);
    return root;
}
string levelOrderTraversal(TreeNode *root){
    queue<TreeNode*> q;
    q.push(root);
    string s = "";
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        if(node){
            s.append(to_string(node->val) + ' ');
            q.push(node->left);
            q.push(node->right);
        }
        else{
            s.append("null ");
        }
    }
    return s;
}
int main(){
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    cout<<"Before: "<<levelOrderTraversal(root)<<endl;
    root = insertIntoBST(root, 5);
    cout<<"After: "<<levelOrderTraversal(root)<<endl;
}