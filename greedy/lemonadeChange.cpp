#include<iostream>
#include<vector>
using namespace std;
bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0, twenty = 0;
    for(int i: bills){
        if(i == 5)
            five++;
        else if(i == 10){
            if(five){
                five--;
                ten++;
            }
            else
                return false;
        }
        else{
            if(ten and five){
                ten--;
                five--;
            }
            else if(five>=3){
                five -= 3;
            }
            else
                return false;
        }
    }
    return true;
}
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    if(lemonadeChange(arr))
        cout<<"Change possible"<<endl;
    else
        cout<<"Change not possible"<<endl;
}