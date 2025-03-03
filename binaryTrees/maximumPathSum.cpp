#include<iostream>
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
int findSum(TreeNode *root, int &maxsum){
    if(root == nullptr)
        return 0;
    int leftSum = max(0, findSum(root->left, maxsum));
    int rightSum = max(0, findSum(root->right, maxsum));
    maxsum = max(maxsum, root->val + leftSum + rightSum);
    return root->val + max(leftSum, rightSum);
}
int maxPathSum(TreeNode* root) {
    int maxsum = INT_MIN;
    findSum(root, maxsum);
    return maxsum;
}
int main(){
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout<<"Maximum path sum: "<<maxPathSum(root)<<endl;
}