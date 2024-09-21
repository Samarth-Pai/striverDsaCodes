#include<iostream>
#include<vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>arr){
    int max1 = 0, count = 0;
    for(int i: arr){
        if(i)
            max1 = max(max1, ++count);
        else
            count = 0;
    }
    return max1;
}
int main(){
    int n, ele;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter 0's and 1's : ";
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    int maxConsquitives = findMaxConsecutiveOnes(arr);
    cout<<"Maximum consiquitive 1's: "<<maxConsquitives<<endl;
}