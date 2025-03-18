#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
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
bool build(TreeNode *root, map<int, TreeNode*> &roots, int mini, int maxi){
    if(root == nullptr)
        return true;
    if(root->val <= mini or root->val >= maxi)
        return false;
    if(root->left == nullptr and root->right == nullptr){
        if(roots.find(root->val) != roots.end()){
            TreeNode *next = roots[root->val];
            root->left = next->left;
            root->right = next->right;
            roots.erase(root->val);
        }
    }
    return build(root->left, roots, mini, root->val) and build(root->right, roots, root->val, maxi);
}
TreeNode* canMerge(vector<TreeNode*>& trees) {
    if(trees.size() == 1){
        if(trees[0]->left and trees[0]->left->val > trees[0]->val
        or trees[0]->right and trees[0]->right->val < trees[0]->val)
            return nullptr;
        return trees[0];
    }
    map<int, TreeNode*> leaves;
    map<int, TreeNode*> roots;
    for(TreeNode* tree: trees){
        roots[tree->val] = tree;
        if(tree->left){
            leaves[tree->left->val] = tree->left;
        }
        if(tree->right){
            leaves[tree->right->val] = tree->right;
        }
    }
    TreeNode *root = nullptr;
    for(pair<int, TreeNode*> p: roots){
        if(leaves.find(p.first)==leaves.end()){
            if(root)
                return nullptr;
            root = p.second;
        }
    }
    if(root == nullptr)
        return nullptr;
    bool can = build(root, roots, INT_MIN, INT_MAX);
    if(can and roots.size() == 1)
        return root;
    return nullptr;
}
int main(){
    // cout<<"Nan";
    // TreeNode *r1 = new TreeNode(2);
    // r1->left = new TreeNode(1);
    // TreeNode *r2 = new TreeNode(3);
    // r2->left = new TreeNode(2);
    // r2->right = new TreeNode(5);
    // TreeNode *r3 = new TreeNode(5);
    // r3->left = new TreeNode(4);
    // vector<TreeNode*> arr = {r1, r2, r3};

    // TreeNode *r1 = new TreeNode(5);
    // r1->left = new TreeNode(3);
    // r1->right = new TreeNode(8);
    // TreeNode *r2 = new TreeNode(3);
    // r2->left = new TreeNode(2);
    // r2->right = new TreeNode(6);
    // vector<TreeNode*> arr = {r1, r2};

    // TreeNode *r1 = new TreeNode(2);
    // r1->left = new TreeNode(1);
    // r1->right = new TreeNode(3);
    // TreeNode *r2 = new TreeNode(3);
    // r2->left = new TreeNode(2);
    // vector<TreeNode*> arr = {r1, r2};

    TreeNode *r1 = new TreeNode(1);
    r1->right = new TreeNode(3);
    TreeNode *r2 = new TreeNode(3);
    r2->left = new TreeNode(1);
    TreeNode *r3 = new TreeNode(4);
    r3->left = new TreeNode(2);
    vector<TreeNode*> arr = {r1, r2, r3};

    TreeNode *r4 = canMerge(arr);
    cout<<serialize(r4)<<endl;
}