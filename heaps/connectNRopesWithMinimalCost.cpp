#include<iostream>
#include<queue>
using namespace std;
long long connectRopes(int* arr, int n)
{
    priority_queue<long long, vector<long long>, greater<>> pq;
    for(int i = 0;i<n;i++)
        pq.push(arr[i]);
    long long res = 0;
    while(pq.size() >= 2){
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        res += b + a;
        pq.push(b + a);
    }
    return res;
}
int main(){
    int n;
    cout<<"Enter no. of ropes: ";
    cin>>n;
    int arr[n];
    cout<<"Enter rope sizes: ";
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    cout<<"Minimum cost: "<<connectRopes(arr, n);
}