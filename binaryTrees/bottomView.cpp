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
    or y >= mappa[x].first)
        mappa[x] = {y, node->data};
    traverse(node->left, x-1, y+1, mappa);
    traverse(node->right, x+1, y+1, mappa);
}
vector <int> bottomView(Node *root) {
    vector<int> res;
    map<int, pair<int, int>> mappa;
    traverse(root, 0, 0, mappa);
    for(pair<int, pair<int, int>> p: mappa)
        res.push_back(p.second.second);
    return res;
}
int main(){
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->left->right->left = new Node(10);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->right->left->right = new Node(14);
    vector<int> ans =   bottomView(root);
    cout<<"Bottom view: ";
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
}