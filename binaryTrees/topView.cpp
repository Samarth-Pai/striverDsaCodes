#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data1){
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};
void traverse(Node *node, int x, int y, map<int, pair<int, int>> &mappa){
    if(node == nullptr)
        return;
    if(mappa.find(x) == mappa.end()
    or y < mappa[x].first){
        mappa[x] = {y, node->data};
    }
    traverse(node->left, x-1, y+1, mappa);
    traverse(node->right, x+1, y+1, mappa);
}
vector<int> topView(Node *root) {
    if(root == nullptr)
        return {};
    vector<int> res;
    map<int, pair<int, int>> mappa;
    traverse(root, 0, 0, mappa);
    for(pair<int, pair<int, int>> p: mappa)
        res.push_back(p.second.second);
    return res;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    vector<int> ans = topView(root);
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
}