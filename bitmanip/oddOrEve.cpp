#include<iostream>
using namespace std;
    bool isEven(int n) {
        return !(n & 1);
    }
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    if(isEven(n)) cout<<n<<" is even"<<endl;
    else cout<<n<<" is odd"<<endl;
}