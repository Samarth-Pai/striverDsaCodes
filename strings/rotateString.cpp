#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void leftRotate(string &arr){
    reverse(arr.begin(),arr.begin()+1);
    reverse(arr.begin()+1,arr.end());
    reverse(arr.begin(),arr.end());
}
bool rotateString(string s, string goal) {
    for(int i = 0;i<s.size();i++){
        if(s==goal)
            return true;
        leftRotate(s);
    }
    return false;
}
int main(){
    string s, goal;
    cout<<"Enter two strings: ";
    cin>>s>>goal;

    cout<<"Both strings are "<<(rotateString(s, goal)?"":"not ")<<"rotatable"<<endl;
}