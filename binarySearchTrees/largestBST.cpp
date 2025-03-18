#include<iostream>
#include<climits>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
struct NodeVal{
    int maxi, mini, maxsize;
    NodeVal(int mini, int maxi, int maxsize){
        this->mini = mini;
        this->maxi = maxi;
        this->maxsize = maxsize;
    }
};
NodeVal helper(Node *root){
    if(root == nullptr)
        return NodeVal(INT_MAX, INT_MIN, 0);
    NodeVal l = helper(root->left);
    NodeVal r = helper(root->right);
    if(l.maxi < root->data and r.mini > root->data)
        return NodeVal(min(root->data, l.mini), max(root->data, r.maxi), 1 + l.maxsize + r.maxsize);
    return NodeVal(INT_MIN, INT_MAX, max(l.maxsize, r.maxsize));
}
int largestBst(Node *root)
{
    return helper(root).maxsize;
}
int main(){
    Node *root = new Node(6);
    root->left = new Node(7);
    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    cout<<largestBst(root)<<endl;
}