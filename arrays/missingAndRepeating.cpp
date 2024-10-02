#include<iostream>
#include<vector>
using namespace std;
vector<int> findTwoElement(vector<int>& arr) {
}
int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the array elements with a missing and a repeating number: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    vector<int>missingRepeating = findTwoElement(arr);
    cout<<"Missing number: "<<missingRepeating[0]<<endl;
    cout<<"Repeating number: "<<missingRepeating[1]<<endl;
}