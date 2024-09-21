#include<iostream>
#include<math.h>
using namespace std;
// int sumOfAllDivisors(int n){
//     if(n==1)
//         return 1;
// 	int sum=1,half = n/2;
//     for(int i=2;i<half+1;i++)
//     {
//         if(n%i==0)
//             sum+=i;
//     }
//     return sum + n + sumOfAllDivisors(n-1);
// }
int sumOfAllDivisors(int n){
    if(n==1)
        return 1;
	int sum=0,sq = sqrt(n),nByI;
    for(int i=1;i<=sq;i++)
    {
        if(n%i==0){
            sum+=i;
            nByI = n/i;
            if(nByI!=i)
                sum+=nByI;
        }
    }
    return sum + sumOfAllDivisors(n-1);
}

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"Sum of all the divsors of "<<num<<" is "<<sumOfAllDivisors(num)<<endl;
}
