#include<iostream>
#include<vector>
using namespace std;
class KthLargest {
public:
    vector<int> H;
    int k;
    KthLargest(int k1, vector<int> nums) {
        k = k1;
        for(int num: nums)
            insert(num);
        while(H.size()>k)
            remove();
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
            swap(H[i], H[mini]);
            downheap(mini);
        }
    }
    int remove(){
        if(H.empty()) return -1;
        int temp = H[0];
        int last = H.back();
        H.pop_back();
        if(!H.empty()){
            H[0] = last;
            downheap(0);
        }
        return temp;
    }
    void insert(int val){
        H.push_back(val);
        upheap(H.size() - 1);
    }
    int add(int val) {
        insert(val);
        if (H.size() > k) {
            remove();
        }
        return H[0];
    }
};
int main(){
    KthLargest kthLargest = KthLargest(3, {4, 5, 8, 2});
    cout<<kthLargest.add(3)<<endl; // return 4
    cout<<"hai"<<endl;
    cout<<kthLargest.add(5)<<endl; // return 5
    cout<<kthLargest.add(10)<<endl; // return 5
    cout<<kthLargest.add(9)<<endl; // return 8
    cout<<kthLargest.add(4)<<endl; // return 8
}