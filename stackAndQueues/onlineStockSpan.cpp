#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// Brute approach
// TC: O(No. of days)
// SC: O(Total no. of calls)
// class StockSpanner {
// public:
//     vector<int> arr;
//     int next(int price) {
//         arr.push_back(price);
//         int cnt = 1;
//         for(int i = arr.size()-2;i>=0;i--){
//             if(arr[i]<=price) cnt++;
//             else break;
//         }
//         return cnt;
//     }
// };

// Optimal solution
// TC: O(2N)
// SC: O(N)
class StockSpanner {
public:
    stack<pair<int, int>> st;
    int ind = -1;
    StockSpanner() {
    }
    
    int next(int price) {
        ind = ind + 1;
        while(!st.empty() and st.top().first<=price)
            st.pop();
        int ans = ind - (st.empty()?-1:st.top().second);
        st.push({price, ind});
        return ans;
    }
};
int main(){
    StockSpanner stockSpanner = StockSpanner();
    cout<<stockSpanner.next(100)<<endl; // return 1
    cout<<stockSpanner.next(80)<<endl;  // return 1
    cout<<stockSpanner.next(60)<<endl;  // return 1
    cout<<stockSpanner.next(70)<<endl;  // return 2
    cout<<stockSpanner.next(60)<<endl;  // return 1
    cout<<stockSpanner.next(75)<<endl;  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    cout<<stockSpanner.next(85)<<endl;  // return 6
}