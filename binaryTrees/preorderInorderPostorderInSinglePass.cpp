#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
typedef pair<TreeNode*, int> pii;
// TC: O(3N)
// SC: O(4N)
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    stack<pii> st;
    st.push({root, 1});
    while(!st.empty()){
        pii node = st.top();
        st.pop();
        if(node.second == 1){
            preorder.push_back(node.first->data);
            node.second++;
            st.push(node);
            if(node.first->left)
                st.push({node.first->left, 1});
        }
        else if(node.second == 2){
            inorder.push_back(node.first->data);
            node.second++;
            st.push(node);
            if(node.first->right)
                st.push({node.first->right, 1});
        }
        else{
            postorder.push_back(node.first->data);
        }
    }
    return {inorder, preorder, postorder};
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left =  new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans = getTreeTraversal(root);
    cout<<"Inorder traversal: ";
    for(int i: ans[0])
        cout<<i<<" ";
    cout<<endl<<"Pre-order traversal: ";
    for(int i: ans[1])
        cout<<i<<" ";
    cout<<endl<<"Post-order traversal: ";
    for(int i: ans[2])
        cout<<i<<" ";
    cout<<endl;
}