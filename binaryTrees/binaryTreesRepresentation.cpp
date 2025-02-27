#include<iostream>
#include<vector>
using namespace std;
// struct node{
//     int data;
//     node *left;
//     node *right;
//     node(int data1){
//         data = data1;
//         left = nullptr;
//         right = nullptr;
//     }
// };
struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}
void create(node *root, vector<int> &arr, int ind){
    int l = 2 * ind + 1;
    int r = 2 * ind + 2;
    if(l < arr.size()){
        root->left = newNode(arr[l]);
        create(root->left, arr, l);
    }
    if(r < arr.size()){
        root->right = newNode(arr[r]);
        create(root->right, arr, r);
    }
}
void create_tree(node* root0, vector<int> &vec){
    root0->data = vec[0];
    create(root0, vec, 0);
}
int main(){
    int n, ele;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    node *root = newNode(-1);
    create_tree(root, arr);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    cout<<root->left->left->data<<endl;
    cout<<root->left->right->data<<endl;
    cout<<root->right->left->data<<endl;
    cout<<root->right->right->data<<endl;
}