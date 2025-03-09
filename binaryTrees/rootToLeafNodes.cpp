#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void traverse(Node *root, vector<int> &ds, vector<vector<int>> &res){
    if(root == nullptr)
        return;
    if(root->left == nullptr and root->right == nullptr){
        ds.push_back(root->data);
        res.push_back(ds);
        ds.pop_back();
        return;
    }
    ds.push_back(root->data);
    traverse(root->left, ds, res);
    traverse(root->right, ds, res);
    ds.pop_back();
}
vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> res;
    vector<int> ds;
    traverse(root, ds,  res);
    return res;
}
int main(){
    vector<vector<int>> arr;
    Node * root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    vector<vector<int>> res = Paths(root);
    for(vector<int> v: res){
        for(int i: v)
            cout<<i<<" ";
        cout<<endl;
    }
}