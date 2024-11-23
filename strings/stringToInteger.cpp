#include<iostream>
#include<ctype.h>
#include<climits>
#include<math.h>
using namespace std;
int myAtoi(string s) {
    int i = 0, n = s.length();
    
    // Ignoring spaces
    while(i<n and s[i]==' ') i++;

    // Determine if negative or not
    bool isNegative = false;
    if(s[i] == '+' or s[i]=='-'){
        isNegative = s[i] == '-';
        i++;
    }

    // Add to the result
    long res = 0;
    while(i<n and isdigit(s[i])){
        res = res * 10 + (s[i++] - '0');
        if(res>INT_MAX)
            return isNegative?INT_MIN:INT_MAX;
    }
    return isNegative?-res:res;
}

int main(){
    string s;
    cout<<"Enter a number with whitespaces and characters mixed: ";
    getline(cin, s);

    cout<<"Number is "<<myAtoi(s)<<endl;

}