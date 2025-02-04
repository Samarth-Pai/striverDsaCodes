#include<iostream>
#include<vector>
using namespace std;

// Brute approach
// TC: O(N*N) + O(N)
// SC: O(2N)
// int celebrity(vector<vector<int> >& mat) {
//     int n = mat.size();
//     vector<int> knowsMe(n);
//     vector<int> iKnow(n);
//     for(int i = 0;i<n;i++){
//         int ikcnt = 0;
//         for(int j = 0;j<n;j++){
//             if(mat[i][j]){
//                 knowsMe[j]++;
//                 iKnow[i]++;
//             }
//         }
//     }
//     for(int i = 0;i<n;i++){
//         if(knowsMe[i]==n-1 and iKnow[i]==0) return i;
//     }
//     return -1;
// }

int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    int top = 0, down = n-1;
    while(top<down){
        if(mat[top][down]==1)
            top++;
        else
            down--;
    }
    // Check column
    for(int i = 0;i<n;i++){
        if(i == top) continue;
        if(mat[i][top] == 0 or mat[top][i] == 1) return -1;
    }
    return top;
}

int main(){
    vector<vector<int>> mat;
    int n, ele;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter the matrix of the order "<<n<<" x "<<n<<endl;
    for(int i = 0;i<n;i++){
        vector<int> row;
        for(int j = 0;j<n;j++){
            cin>>ele;
            row.push_back(ele);
        }
        mat.push_back(row);
    }
    int ans = celebrity(mat);
    cout<<"Celebrity is "<<ans<<endl;
}