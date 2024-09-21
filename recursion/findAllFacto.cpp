#include<iostream>
#include<vector>
using namespace std;
vector<long long> factorialNumbers(long long n) {
    long long fact = 1;
    int i=1;
    vector<long long>nums;
    while(fact<=n){
        nums.push_back(fact);
        fact*=++i;
    }
    return nums;
}

int main(){
    long long num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"Factorial upto "<<num<<" : ";
    for(long long i:factorialNumbers(num))
        cout<<i<<" ";
    cout<<endl;
}

