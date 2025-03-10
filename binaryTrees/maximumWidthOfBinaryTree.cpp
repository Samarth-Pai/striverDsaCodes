#include<iostream>
#include<queue>
#include<climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    int mini, maxi;
    q.push({root, 0});
    int maxwidth = 0;
    while(!q.empty()){
        int n = q.size(), curr, off;
        off = q.front().second;
        for(int i = 0;i<n;i++){
            pair<TreeNode*, int> p = q.front();
            curr = p.second - off;
            if(i == 0)
                mini = curr;
            if(i == n-1)
                maxi = curr;
            q.pop();
            if(p.first->left)
                q.push({p.first->left, 2LL*curr + 1});
            if(p.first->right)
                q.push({p.first->right,  2LL*curr + 2});
        }   
        maxwidth = max(maxwidth, maxi - mini + 1);
    }
    return maxwidth;
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    cout<<"Maximum width of the binary tree: "<<widthOfBinaryTree(root)<<endl;
}