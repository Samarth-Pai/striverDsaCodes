#include<iostream>
#include<vector>
using namespace std;
// Basically same as lower bound
// TC: O(log2 N)
int searchInsert(vector<int> arr, int m)
{
	int n = arr.size(), low = 0, mid;
	int high = n-1, ans = n;
	while(low<=high){
		mid = (low + high)/2;
		if(arr[mid]>=m){
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return ans;
}

int main(){
    int n, ele, target;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
		arr.push_back(ele);
    }
    cout<<"Enter the target: ";
    cin>>target;
    cout<<"Position in which "<<target<<" can be inserted is "<<searchInsert(arr, target)<<endl;
}