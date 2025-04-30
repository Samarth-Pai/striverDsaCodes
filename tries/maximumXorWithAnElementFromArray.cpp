#include<iostream>
#include<vector>
#include<algorithm>
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
            bool bit = num>>i & 1;
            if(!node->containsKey(bit))
                node->put(bit);
            node = node->get(bit);
        }
    }

    int getMax(int x){
        Node *node = root;
        int res = 0;
        for(int i = 31;i>=0;i--){
            bool bit = x>>i & 1;
            if(node->containsKey(!bit)){
                res |= 1<<i;
                node = node->get(!bit);
            }
            else
                node = node->get(bit);
            if(node == nullptr)
                return -1;
        }
        return res;
    }
};

static bool comp(vector<int> &q1, vector<int> &q2){
    return q1[1] < q2[1];
}

// Using tries
// TC: O(N * 32 + Q * logQ + 32 * Q)
// SC: O(N * 32 + Q)
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    Trie *trie = new Trie();
    sort(nums.begin(), nums.end());
    for(int i =0;i<queries.size();i++){
        queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(), comp);
    int i = 0;
    vector<int> res(queries.size());
    for(vector<int> q: queries){
        int xi = q[0], mi = q[1], pos = q[2];
        while(i<nums.size() and nums[i]<=mi){
            trie->insert(nums[i]);
            i++;
        }
        res[pos] =  trie->getMax(xi);
    }
    return res;
}
int main(){
    int n, q;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    cout<<"Enter no. of queries: ";
    cin>>q;
    vector<vector<int>> queries(q, vector<int>(2));
    cout<<"Enter each pair of queries: "<<endl;
    for(int i = 0;i<q;i++)
        cin>>queries[i][0]>>queries[i][1];
    vector<int> ans = maximizeXor(nums, queries);
    cout<<"Maximums: ";
    for(int i: ans)
        cout<<i<<' ';
    cout<<endl;
}