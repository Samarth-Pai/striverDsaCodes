#include<iostream>
using namespace std;
// TC: O(start^goal)
// SC: O(1)
int minBitFlips(int start, int goal) {
    int cnt = 0, ans = start ^ goal;
    for(int i = 0;i<=31;i++)
        if(ans & 1<<i) cnt++;
    return cnt;
}
int main(){
    int n, goal;
    cout<<"Enter a number and goal number to count bit flips: ";
    cin>>n>>goal;
    cout<<"No. of bit flips = "<<minBitFlips(n, goal)<<endl;
}