#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class DisjointSet{
    public:
    vector<int> rank, parent;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        for(int i = 0;i<=n;i++)
            parent[i] = i;
    }
    int findUPar(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int upar = findUPar(u);
        int vpar = findUPar(v);
        if(upar == vpar)
            return;
        if(rank[upar] < rank[vpar])
            parent[upar] = vpar;
        else if(rank[upar] > rank[vpar])
            parent[vpar] = upar;
        else{
            parent[vpar] = upar;
            rank[upar]++;
        }
    }
};
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    map<string, int> mappa;
    int n = accounts.size();
    DisjointSet dsu(n);
    for(int i = 0;i<n;i++){
        for(int j = 1;j<accounts[i].size();j++){
            if(mappa.find(accounts[i][j]) == mappa.end()){
                mappa[accounts[i][j]] = i;
            }
            else{
                dsu.unionByRank(mappa[accounts[i][j]], i);
            }
        }
    }
    vector<vector<string>> mergedMails(n);
    for(pair<string, int> p: mappa){
        string mail = p.first;
        int node = dsu.findUPar(p.second);
        mergedMails[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for(int i = 0;i<n;i++){
        if(mergedMails[i].empty())
            continue;
        vector<string> row = {accounts[i][0]};
        sort(mergedMails[i].begin(), mergedMails[i].end()); 
        row.insert(row.begin()+1, mergedMails[i].begin(), mergedMails[i].end());
        ans.push_back(row);
    }
    return ans;
}
int main(){
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };
    vector<vector<string>> merged = accountsMerge(accounts);
    cout<<"Merged accounts: ";
    for(vector<string> s: merged){
        cout<<s[0]<<": ";
        for(int i = 1;i<s.size();i++)
            cout<<s[i]<<' ';
        cout<<endl;
    }
    return 0;
}