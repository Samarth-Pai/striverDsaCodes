#include<iostream>
using namespace std;

void pattern01(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<"* ";
        cout<<endl;
    }
}
void pattern02(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
            cout<<"* ";
        cout<<endl;
    }
}
void pattern03(int n){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<=i;j++)
            cout<<j<<" ";
        cout<<endl;
    }
}
void pattern04(int n){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<=i;j++)
            cout<<i<<" ";
        cout<<endl;
    }
}
void pattern05(int n){
    for(int i=0;i<n;i++){
        for(int j=n;j>i;j--)
            cout<<"* ";
        cout<<endl;
    }
}
void pattern06(int n){
    for(int i=n;i>=1;i--){
        for(int j=1;j<i+1;j++)
            cout<<j<<" ";
        cout<<endl;
    }
}
void pattern07(int n){
    for(int i=n;i>0;i--){
        for(int j=1;j<i;j++)
            cout<<" ";
        for(int j=0;j<(n-i)*2+1;j++)
            cout<<"*";
        for(int j=1;j<i;j++)
            cout<<" ";
        cout<<endl;
    }
}
void pattern08(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++)
            cout<<" ";
        for(int j=0;j<2*(n-i-1)+1;j++)
            cout<<"*";
        for(int j=0;j<i;j++)
            cout<<" ";
        cout<<endl;
    }
}
void pattern09(int n){
    int j,m;
    for(int i=0;i<2*n;i++){
        if(i<n){
            for(j=0;j<n-i-1;j++)
                cout<<" ";
            for(j=0;j<2*i+1;j++)
                cout<<"*";
            for(j=0;j<n-i-1;j++)
                cout<<" ";
        }
        else{
            for(j=0;j<i-n;j++)
                cout<<" ";
            for(j=0;j<2*(2*n-i-1)+1;j++)
                cout<<"*";
            for(j=0;j<i-n;j++)
                cout<<" ";
        }
        cout<<endl;
    }
}
void pattern10(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++)
            cout<<"*";
        cout<<endl;
    }
    for(i=n-1;i>0;i--){
        for(j=i;j>0;j--)
            cout<<"*";
        cout<<endl;
    }
}
void pattern11(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=i;j>0;j--)
            cout<<j%2<<" ";
        cout<<endl;
    }
}
void pattern12(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=1;j<=i+1;j++)
            cout<<j<<" ";
        for(j=0;j<2*(n-i-1);j++)
            cout<<"  ";
        for(j=i+1;j>0;j--)
            cout<<j<<" ";
        cout<<endl;
    }
}
void pattern13(int n){
    int i,j,k=1;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++)
            cout<<k++<<" ";
        cout<<endl;
    }
}
void pattern14(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++)
            cout<<static_cast<char>(j+65)<<" ";
        cout<<endl;
    }
}
void pattern15(int n){
    char ch;
    for(int i=n-1;i>=0;i--){
        ch = 'A';
        for(int j=0;j<=i;j++)
            cout<<ch++<<" ";
        cout<<endl;
    }
}
void pattern16(int n){
    int i,j;
    char ch = 'A';
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++)
            cout<<ch<<' ';
        ch++;
        cout<<endl;
    }
}
void pattern17(int n){
    int i,j;
    char ch;
    for(i=0;i<n;i++){
        ch = 'A';
        for(j=0;j<n-i-1;j++)
            cout<<"  ";
        for(j=0;j<=i;j++)
            cout<<ch++<<' ';
        ch--;
        for(j=0;j<i;j++)
            cout<<--ch<<' ';
        for(j=0;j<n-i-1;j++)
            cout<<"  ";
        cout<<endl;
    }
}
void pattern18(int n){
    int i,j;
    char ch;
    for(i=0;i<n;i++){
        ch = 64 + n;
        for(j=0;j<=i;j++)
            cout<<ch--<<' ';
        cout<<endl;
    }
}
void pattern19(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++)
            cout<<"* ";
        for(j=0;j<2*i;j++)
            cout<<"  ";
        for(j=0;j<n-i;j++)
            cout<<"* ";
        cout<<endl;
    }
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++)
            cout<<"* ";
        for(j=0;j<2*(n-i-1);j++)
            cout<<"  ";
        for(j=0;j<=i;j++)
            cout<<"* ";
        cout<<endl;
    }
}
void pattern20(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++)
            cout<<"* ";
        for(j=0;j<2*(n-i-1);j++)
            cout<<"  ";
        for(j=0;j<=i;j++)
            cout<<"* ";
        cout<<endl;
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++)
            cout<<"* ";
        for(j=0;j<2*(i+1);j++)
            cout<<"  ";
        for(j=0;j<n-i-1;j++)
            cout<<"* ";
        cout<<endl;
    }
}
void pattern21(int n){
    int i,j;
    for(i=0;i<n;i++){
        if(i==0 or i==n-1)
            for(j=0;j<n;j++)
                cout<<"*";
        else{
            cout<<"*";
            for(j=0;j<n-2;j++)
                cout<<" ";
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern22(int n){
    int i,j,k;
    for(i=0;i<n;i++){
        k = n-i;
        for(j=0;j<i;j++)
            cout<<n-j;
        for(j=0;j<2*k-1;j++)
            cout<<k;
        for(j=k+1;j<=n;j++)
            cout<<j;
        k--;
        cout<<endl;
    }
    for(i=n-2;i>=0;i--){
        k = n-i;
        for(j=0;j<i;j++)
            cout<<n-j;
        for(j=0;j<2*k-1;j++)
            cout<<k;
        for(j=k+1;j<=n;j++)
            cout<<j;
        k--;
        cout<<endl;
    }
}
int main(){
    int n = 5;
    pattern22(n);
}