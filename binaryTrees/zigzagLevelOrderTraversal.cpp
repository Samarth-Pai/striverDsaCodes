#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root == nullptr)
        return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> res;
    bool flag = false;
    while(!q.empty()){
        int n = q.size();
        vector<int> arr(n);
        for(int i = 0;i<n;i++){
            TreeNode *node = q.front();
            q.pop();
            int ind = flag?n-1-i:i;
            arr[ind] = node->val;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        res.push_back(arr);
        flag = ! flag;
    }
    return res;
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    vector<vector<int>> ans = zigzagLevelOrder(root);
    for(vector<int> v: ans){
        for(int i: v) cout<<i<<' ';
        cout<<endl;
    }
}