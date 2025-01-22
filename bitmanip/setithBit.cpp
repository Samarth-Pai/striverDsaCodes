#include<iostream>
using namespace std;
int setIthBit(int n, int i){
    return n | 1<<i;
}
int main(){
    int n, i;
    cout<<"Enter n and ith pos to set the bit: ";
    cin>>n>>i;
    cout<<n<<" after setting "<<i<<" th bit: "<<setIthBit(n, i)<<endl;
}