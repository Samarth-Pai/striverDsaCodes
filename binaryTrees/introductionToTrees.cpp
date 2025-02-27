#include<iostream>
using namespace std;
int countNodes(int i) {
    return 1<<(i-1);
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"No. of nodes at level "<<n<<" is "<<countNodes(n)<<endl;
    return 0;
}