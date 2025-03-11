#include<iostream>
#include<vector>
#include<map>
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
void markParents(TreeNode *root, map<TreeNode*, TreeNode*> &parents){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0;i<n;i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left){
                parents[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parents[node->right] = node;
                q.push(node->right);
            }
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    map<TreeNode*, TreeNode*> parents;
    markParents(root, parents);
    map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true; 
    vector<int> res;
    int currLevel = 0;
    while(!q.empty()){
        int n = q.size();
        if(currLevel++ == k)
            break;
        for(int i = 0;i<n;i++){
            TreeNode *node = q.front();
            q.pop();
            cout<<node->val<<endl;
            if(node->left and !visited[node->left]){
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right and !visited[node->right]){
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parents[node] and !visited[parents[node]]){
                q.push(parents[node]);
                visited[parents[node]] = true;
            }
        }
    }
    while(!q.empty()){
        res.push_back(q.front()->val);
        q.pop();
    }
    return res;
}
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode *target = root->left;
    int k = 2;
    vector<int> res = distanceK(root, target, k);
    cout<<"Nodes: ";
    for(int i: res)
        cout<<i<<" ";
    cout<<endl;
}