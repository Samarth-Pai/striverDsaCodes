#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool customComp(pair<int,int>p1, pair<int,int>p2){
    if(p1.second!=p2.second)
        return p2.second>p1.second;
    return p1.first>p2.first;
}
int main(){
    // sort function
    vector<int>a {20,30,10,50,40,25};
    vector<int>b = a;
    vector<int>c = b;
    sort(a.begin(),a.end()); // sorts all the elements of the vector
    sort(b.begin()+1,b.begin()+4); // sorts the elements of the index 1,2,3 of the vector
    for(int i:b)
        cout<<i<<' ';
    cout<<endl;

    int d[]={20,30,10,50,40,25};
    sort(d,d+4,greater<int>()); // sorting first 4 elements only but in descending order
    for(int i:d)
        cout<<i<<' ';
    cout<<endl;
    // sorting with custom comparator
    pair<int,int>p[] =  {{1,2},{4,1},{2,1},{3,2}};
    // task: to sort in considering index 1 in ascending order and if they are same then index 0 in descending order
    // in this case the ouput that is expected to be is {{4,1}, {2,1}, {3,2}, {1,2}}
    sort(p,p+4,customComp);
    for(pair<int,int> i:p)
        cout<<i.first<<" : "<<i.second<<endl;

    int n = 7;
    cout<<__popcount(n)<<endl; // return 3 as binary representation of 7 has three 1 bits
    
    // getting permutaion of a string
    string s="1234"; // 4! = 24
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));

    // max element from an array
    int arr[] = {1,20,24,90,50};
    int maxx = *max_element(arr,arr+5);
    cout<<"Max element: "<<maxx<<endl;
}