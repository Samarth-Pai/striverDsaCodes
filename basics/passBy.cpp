// To demonstrate pass by reference and ref 
#include<iostream>
using namespace std;

// pass by value
void print2value(int n){
    cout<<"Number passed: "<<n<<endl;
    n+=5;
    cout<<"Number after incrementing it by 5: "<<n<<endl;
}

// pass by reference(by address)
void print2addr(int &n){
    cout<<"Number passed(addr): "<<n<<endl;
    n+=5;
    cout<<"Number after incrementing it by 5(addr): "<<n<<endl;
}
int main(){
    int v, r;
    cout<<"Enter a nummber: ";
    cin>>v;
    r = v;

    cout<<"Pass by value: ";
    print2value(v);
    cout<<"After pass by value: "<<v<<endl<<endl;

    cout<<"Pass by address: ";
    print2addr(r);
    cout<<"After pass by ref(addr): "<<r<<endl;


}