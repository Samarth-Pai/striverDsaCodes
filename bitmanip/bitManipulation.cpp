#include<iostream>
using namespace std;
int pow(int num, int i){
    if(i == 0) return 1;
    return num * pow(num, i-1);
}
void bitManipulation(int num, int i) {
    int temp = num, j = i;
    bool s;
    while(i-1){
        temp/=2;
        i--;
    }
    s = temp%2;
    if(s) cout<<s<<" "<<num<<" "<<num - pow(2, j-1)<<endl;
    else cout<<s<<" "<<num + pow(2, j-1)<<" "<<num<<endl;
}
// 0 129975316 129909780
// 0 129975316 129909780
// 0 129975316 129909780
int main(){
    int num, i;
    cout<<"Enter a number and ith bit position: ";
    cin>>num>>i;
    bitManipulation(num, i);
    cout<<endl;
}