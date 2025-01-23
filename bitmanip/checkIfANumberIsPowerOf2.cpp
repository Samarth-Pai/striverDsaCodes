#include<iostream>
using namespace std;
bool isPowerOfTwo(int n){   
    if(n<=0) return 0;
    return (n & (n-1)) == 0;
}
int main(){
    int n, i;
    cout<<"Enter a number: ";
    cin>>n;
    if(isPowerOfTwo(n)) cout<<n<<" is a power of 2"<<endl;
    else cout<<n<<" is not a power of 2"<<endl;
}