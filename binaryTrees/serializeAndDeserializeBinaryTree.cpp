#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Using BFS
// TC: O(N)
// SC: O(N)
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

// TreeNode *deserialize(string data){
//     if(data.empty())
//         return nullptr;
//     vector<string> stream;
//     stringstream ss(data);
//     string s;
//     while(ss >> s){
//         stream.push_back(s);
//     }
//     queue<TreeNode*> q;
//     TreeNode *root = new TreeNode(stoi(stream[0]));
//     q.push(root);
//     int i = 1;
//     while(!q.empty() and i<stream.size()){
//         TreeNode *node = q.front();
//         q.pop();
//         if(i < stream.size() and stream[i]!="null"){
//             node->left = new TreeNode(stoi(stream[i]));
//             q.push(node->left);
//         }
//         i++;
//         if(i < stream.size() and stream[i]!="null"){
//             node->right = new TreeNode(stoi(stream[i]));
//             q.push(node->right);
//         }
//         i++;
//     }
//     return root;
// }

// Optimized space
// TC: O(N)
// SC: O(N)
TreeNode *deserialize(string data){
    if(data.empty())
        return nullptr;
    stringstream ss(data);
    string s;
    queue<TreeNode*> q;
    getline(ss, s, ' ');
    TreeNode *root = new TreeNode(stoi(s));
    q.push(root);
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        if(getline(ss, s, ' ') and s!="null"){
            node->left = new TreeNode(stoi(s));
            q.push(node->left);
        }
        if(getline(ss, s, ' ') and s!="null"){
            node->right = new TreeNode(stoi(s));
            q.push(node->right);
        }
    }
    return root;
}


int main(){
    string s;
    cout<<"Enter binary tree heap: ";
    getline(cin, s);
    TreeNode *root = deserialize(s);
    string serializedS = serialize(root);
    cout<<"Serialized binary tree: "<<serializedS<<endl;
}