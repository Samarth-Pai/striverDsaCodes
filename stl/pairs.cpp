#include<iostream>
// #include<utility>
using namespace std;
int main(){
    pair<int ,int>p;
    cout<<"Enter two numbers: ";
    cin>>p.first>>p.second;
    cout<<"Sum: "<<p.first+p.second<<endl;
    
    pair<int,pair<int,int>>a = {1,{2,3}};
    cout<<a.first<<a.second.first<<a.second.second;
    cout<<endl;

    int n = 5;
    pair<int,char>mala[n];
    cout<<"Enter a number corresponding to char 5 times: "<<endl;
    for(int i=0;i<n;i++)
        cin>>mala[i].first>>mala[i].second;
    cout<<endl<<"Entered values: "<<endl;
    for(int i=0;i<n;i++)
        cout<<mala[i].first<<" : "<<mala[i].second<<endl;
}   