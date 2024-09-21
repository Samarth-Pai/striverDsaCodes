#include<iostream>
using namespace std;
int main(){
    // 1D arrays
    int arr[5] = {124,551,151,115,77};
    arr[3]+=11;
    cout<<arr[3]<<endl;

    // 2D array
    int arr2[3][4];
    arr2[1][3] = 123;
    cout<<arr2[0][0]<<" "<<arr2[1][3]<<endl;
}