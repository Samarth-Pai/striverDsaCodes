#include<iostream>
#include<queue>
#include<set>
#include<map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> mappa;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while(!q.empty()){
        pair<TreeNode*, pair<int, int>> p = q.front();
        q.pop();
        TreeNode *node = p.first;
        int x = p.second.first, y = p.second.second;
        mappa[x][y].insert(node->val);
        if(node->left)
            q.push({node->left, {x-1, y+1}});
        if(node->right)
            q.push({node->right, {x+1, y+1}});
    }
    vector<vector<int>> ans;
    for(pair<int, map<int, multiset<int>>> ufotable: mappa){
        vector<int> col;
        for(pair<int, multiset<int>> p: ufotable.second)
            col.insert(col.end(), p.second.begin(), p.second.end());
        ans.push_back(col);
    }
    return ans;
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left =  new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans = verticalTraversal(root);
    for(vector<int> v: ans){
        for(int i: v)   
            cout<<i<<" ";
        cout<<endl;
    }
}