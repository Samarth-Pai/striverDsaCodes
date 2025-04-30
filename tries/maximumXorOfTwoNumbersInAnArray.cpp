#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    Node *links[2];

    bool containsKey(bool key){
        return links[key] != nullptr;
    }

    void put(bool key){
        links[key] = new Node();
    }

    Node *get(bool key){
        return links[key];
    }
    
};

class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node *node = root;
        for(int i = 31;i>=0;i--){
            if(!node->containsKey(num>>i & 1))
                node->put(num>>i & 1);
            node = node->get(num>>i & 1);
        }
    }

    int getMax(int num){
        int res = 0;
        Node *node = root;
        for(int i = 31;i>=0;i--){
            if(node->containsKey(!(num>>i & 1))){
                res |= 1<<i;
                node = node->get(!(num>>i & 1));
            }
            else
                node = node->get(num>>i & 1);
            if(node == nullptr)
                break;
        }
        return res;
    }
};

// Using Trie
// TC: O(N * 32)
// SC: O(N * 32)
int findMaximumXOR(vector<int>& nums) {
    Trie *trie = new Trie();
    for(int num: nums)
        trie->insert(num);
    int maxi = 0;
    for(int num: nums)
        maxi = max(maxi, trie->getMax(num));
    return maxi;
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    vector<int> nums(n);
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    cout<<"Maximum XOR: "<<findMaximumXOR(nums)<<endl;
}