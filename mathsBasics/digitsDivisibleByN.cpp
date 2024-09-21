#include<iostream>
using namespace std;

class Solution{
public:
    int evenlyDivides(int N){
        int digit,count = 0;
        int orgN = N;
        while(N){
            digit = N%10;
            if(digit)
                count+=orgN%digit==0;
            N/=10;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Number of digits in "<<n<<" that is divisible by its digits: "<<sol.evenlyDivides(n)<<endl;
}