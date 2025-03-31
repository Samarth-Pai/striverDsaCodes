#include<iostream>
using namespace std;

int find(int par[], int x) {
    if(x ==  par[x])
        return x;
    return par[x] = find(par, par[x]);
}

void unionSet(int par[], int x, int z) {
    int upx = find(par, x);
    int upz = find(par, z);
    par[upx] = upz;
}
int main(){
    int n = 5;
    int par[n] = {0, 1, 2, 3, 4, 5};
    cout<<find(par, 4)<<endl;
    cout<<find(par, 1)<<endl;
    unionSet(par, 3, 1);
    cout<<find(par, 3)<<endl;
}