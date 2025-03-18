#include<iostream>
#include<vector>
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
string serialize(TreeNode* root) {
    if(root == nullptr)
        return "";
    string s;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        if(node){
            s.append(to_string(node->val) + ' ');
            q.push(node->left);
            q.push(node->right);
        }
        else
            s.append("null ");
    }
    s.pop_back();
    return s;
}
// TC: O(N)
// SC: O(1)
void recoverTree(TreeNode* root) {
    TreeNode *first = nullptr, *mid = nullptr, *last = nullptr;
    TreeNode *node = root, *prev = nullptr;
    while(node){
        if(node->left == nullptr){
            if(prev and node->val < prev->val){
                if(first == nullptr){
                    first = prev;
                    mid = node;
                }
                else if(last == nullptr){
                    last = node;
                }
            }
            prev = node;
            node = node->right;
        }
        else{
            TreeNode *rightmost = node->left;
            while(rightmost->right and rightmost->right!=node){
                rightmost = rightmost->right;
            }
            if(rightmost->right){
                if(prev and node->val < prev->val){
                    if(first == nullptr){
                        first = prev;
                        mid = node;
                    }
                    else if(last == nullptr){
                        last = node;
                    }
                }
                prev = node;
                rightmost->right = nullptr;
                node = node->right;
            }
            else{
                rightmost->right = node;
                node = node->left;
            }
        }
    }
    if(first and last)
        swap(first->val, last->val);
    else
        swap(first->val, mid->val);
}
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    recoverTree(root);
    cout<<serialize(root)<<endl;
}