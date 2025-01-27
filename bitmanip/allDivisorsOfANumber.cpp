#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// TC: O(N)
// SC: O(1)
// void print_divisors(int n) {
//     for(int i = 1;i<=n;i++)
//         if(n%i == 0) cout<<i<<" ";
//     cout<<endl;
// }

// TC: O(sqrt(N))
// SC: O(1) because the order doesnt actually matter, but for printing purposes we are storing the divisors into an array and sorting them
void print_divisors(int n){
    vector<int> a;
    for(int i = 1;i*i<=n;i++){
        if(n%i == 0){
            a.push_back(i);
            if(n/i!=i) a.push_back(n/i);
        }
    }
    sort(a.begin(), a.end());
    for(int i: a) cout<<i<<" ";
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    print_divisors(n);
}