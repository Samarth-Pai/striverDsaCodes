#include<iostream>
#include<vector>
using namespace std;
bool isBSTTraversal(vector<int>& arr) {
    for(int i = 1;i<arr.size();i++){
        if(arr[i] <= arr[i-1])
            return false;
    }
    return true;
}
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter inorder traversal of a binary tree: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    bool ans = isBSTTraversal(arr);
    if(ans)
        cout<<"Given binary tree is a binary search tree"<<endl;
    else
        cout<<"Given binary tree is not a binary search tree"<<endl;
}