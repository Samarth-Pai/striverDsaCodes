#include<iostream>
using namespace std;
void printNos(int n){
    if(n){
        cout<<n<<" ";
        printNos(n-1);
    }
}
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    printNos(num);
    cout<<endl;
}