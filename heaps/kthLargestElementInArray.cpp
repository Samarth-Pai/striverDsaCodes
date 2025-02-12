#include<iostream>
#include<vector>
using namespace std;
class heap{
    vector<int> H;
    public:
    heap(){}
    heap(vector<int> &arr){
        for(int i: arr)
            insert(i);
    }

    void downhead(int i){
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int maxi = i;
        if(l < H.size() and H[l] > H[maxi])
            maxi = l;
        if(r < H.size() and H[r] > H[maxi])
            maxi = r;
        if(maxi != i){
            swap(H[maxi], H[i]);
            downhead(maxi);
        }
    }

    void uphead(int i){
        if(i == 0) return;
        int p = (i - 1)/2;
        if(H[p] < H[i]){
            swap(H[p], H[i]);
            uphead(p);
        }
    }

    void insert(int val){
        H.push_back(val);
        uphead(H.size() - 1);
    }

    int remove(){
        int temp = H[0];
        int last = H.back();
        H.pop_back();
        if(!H.empty()){
            H[0] = last;
            downhead(0);
        }
        return temp;
    }
};

int findKthLargest(vector<int>& nums, int k) {
    heap maxHeap = heap(nums);
    for(int i = 0;i<k-1;i++)
        maxHeap.remove();
    return maxHeap.remove();
}

int main(){
    int n, ele, k;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter k: ";
    cin>>k;
    cout<<k<<" th largest element of the array is "<<findKthLargest(arr, k)<<endl;
}