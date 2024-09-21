#include<iostream>
using namespace std;
int main(){
    int marks;
    cout<<"Enter your marks: ";
    cin>>marks;
    cout<<"Your grade: ";
    if(marks<25)
        cout<<'F';
    else if(marks<45)
        cout<<'E';
    else if(marks<50)
        cout<<'D';
    else if(marks<60)
        cout<<'C';
    else if(marks<80)
        cout<<'B';
    else if(marks<101)
        cout<<'A';
    else
        cout<<'F';
    cout<<endl;
}

/*
a. Below 25-F
b. 25 to 44-E
c. 45 to 49-D
d. 50 to 59-C
e. 60 to 79-8
f. 80 to 100-A
Ask user to enter marks and print the corresponding grade.
*/