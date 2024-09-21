#include<iostream>
using namespace std;
void printNos(int n){
    if(n){
        printNos(n-1);
        cout<<n<<" ";
    }
}
using namespace std;
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    printNos(num);
    cout<<endl;
}
