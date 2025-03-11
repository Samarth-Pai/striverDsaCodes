#include<iostream>
#include<queue>
#include<map>
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
typedef map<Node*, Node*> mnn;
typedef map<Node*, bool> mnb;
void markParents(Node *root,mnn &parents){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0;i<n;i++){
            Node *node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parents[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parents[node->right] = node;
            }
        }
    }
}
Node *getTarget(Node *root, int target){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0;i<n;i++){
            Node *node = q.front();
            q.pop();
            if(node->data == target)
                return node;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    return nullptr;
}
int minTime(Node* root, int target) {
    mnn parents;
    markParents(root, parents);
    Node* targetNode = getTarget(root, target);
    queue<Node*> q;
    q.push(targetNode);
    mnb visited;
    visited[targetNode] = true;
    int cnt = 0;
    while(!q.empty()){
        int n = q.size();
        for(int i = 0;i<n;i++){
            Node * node = q.front();
            q.pop();
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
        cnt++;
    }
    return cnt - 1;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right = new Node(6);
    root->right->right->right = new Node(9);
    root->right->right->right->right = new Node(10);
    // Node * root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(2);
    // root->left->right = new Node(5);
    // root->left->right->left = new Node(7);
    // root->left->right->right = new Node(8);
    // root->right->right = new Node(6);
    // root->right->right->right = new Node(9);
    // root->right->right->right->right = new Node(10);
    int target = 8;
    cout<<"Minimmum time: "<<minTime(root, target)<<endl;
}