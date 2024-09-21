/*Take the age from the user and then decide accordingly
1. If age 18,
print not eligible for job
2. If age 18,
print-> "eligble for job"
3. If age 55 and age 57,
print "eligible for job, but retirement soon."
4. If age > 57
print "retirement time"
*/

#include<iostream>
using namespace std;
int main(){
    int age;
    cout<<"Enter user age: ";
    cin>>age;
    if(age<18)
        cout<<"not eligible for job";
    else{
        if(age<=57){
            cout<<"eligible for job";
            if(age>=55)
                cout<<", but retirement soon";
        }
        else
            cout<<"retirement time";
    }
    cout<<endl;
}