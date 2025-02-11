#include<iostream>
#include<vector>
using namespace std;
class maxHeap{
    vector<int> H;
    public:

    // O(N)
    maxHeap(vector<int> &arr){
        int n = arr.size();
        H = arr;
        for(int i = n/2;i>=0;i--){
            downheap(i);
        }
    }

    // O(1)
    int parent(int i){
        return (i - 1)/2;
    }

    // O(1)
    int left(int i){
        return i * 2 +1;
    }

    // O(1)
    int right(int i){
        return i * 2 + 2;
    }

    // O(logN)
    void upheap(int i){
        if(i == 0) return;
        int p = parent(i);
        if(H[p] < H[i]){
            swap(H[p], H[i]);
            upheap(p);
        }
    }

    // O(logN)
    void downheap(int i){
        int mini = i, l = left(i), r = right(i);
        if(l < H.size() and H[l] > H[mini]){
            mini = l;
        }

        if(r < H.size() and H[r] > H[mini]){
            mini = r;
        }
        if(mini != i){
            swap(H[i], H[mini]);
            downheap(mini);
        }
    }

    // O(logN)
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

    // O(logN)
    void insert(int val){
        H.push_back(val);
        upheap(H.size() - 1);
    }

    vector<int> heapsort(){
        vector<int> data;
        while(!H.empty())
            data.push_back(remove());
        return data;
    }
};

int main(){
    // maxHeap h = maxHeap();
    // h.insert(10);
    // h.insert(2);
    // h.insert(4);
    // h.insert(5);
    // h.insert(7);
    // h.insert(2);
    vector<int> arr = {10, 2, 4, 5, 7, 2};
    maxHeap h = maxHeap(arr);
    vector<int> res = h.heapsort();
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}