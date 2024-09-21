#include<iostream>
#include<vector>
using namespace std;
void frequencyCount(vector<int>& arr, int N, int P) {
    vector<int>newArr(N);
    for(int i: arr)
        if(i<=N)
            newArr[i-1]++;
    arr.swap(newArr);
}
int main(){
    int n, ele, p;
    vector<int>eles;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the max value that you are gonna enter: ";
    cin>>p;
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        eles.push_back(ele);
    }
    frequencyCount(eles, n, p);
    cout<<"Hash array: ";
    for(int i: eles)
        cout<<i<<" ";
    cout<<endl;
}
