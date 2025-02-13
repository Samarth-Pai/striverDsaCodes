#include<iostream>
#include<vector>
using namespace std;
class minHeap{
    vector<int> H;
    public:
    minHeap(vector<int> &arr){
        for(int i: arr)
            insert(i);
    }
    void upheap(int i){
        if(i == 0) return;
        int p = (i - 1)/2;
        if(H[p] > H[i]){
            swap(H[p], H[i]);
            upheap(p);
        }
    }
    
    void downheap(int i){
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int mini = i;
        if(l < H.size() and H[l] < H[mini])
            mini = l;
        if(r < H.size() and H[r] < H[mini])
            mini = r;
        if(mini != i){
            swap(H[mini], H[i]);
            downheap(mini);
        }
    }
    
    void insert(int val){
        H.push_back(val);
        upheap(H.size() - 1);
    }
    
    int extractMin(){
        int temp = H[0];
        int last = H.back();
        H.pop_back();
        if(!H.empty()){
            H[0] = last;
            downheap(0);
        }
        return temp;
    }
};
int kthSmallest(vector<int> &arr, int k) {
    minHeap h = minHeap(arr);
    for(int i = 0;i<k-1;i++)
        h.extractMin();
    return h.extractMin();
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
    cout<<k<<" th smallest element of the array is "<<kthSmallest(arr, k)<<endl;
}