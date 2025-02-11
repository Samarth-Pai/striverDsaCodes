#include<iostream>
#include<vector>
using namespace std;
// Min heap
class heap{
    vector<int> H;
    public:
    // O(1)
    void swapInd(int first, int second){
        swap(H[first], H[second]);
    }

    // O(1)
    int parent(int i){
        return (i - 1)/2;
    }

    // O(1)
    int left(int i){
        return i * 2 + 1;
    }
    
    // O(1)
    int right(int i){
        return i * 2 + 2;
    }

    // O(logN)
    void insert(int val){
        H.push_back(val);
        upheap(H.size() - 1);
    }

    // O(logN)
    void upheap(int i){
        if(i == 0) return;
        int p = parent(i);
        if(H[i] < H[p])
            swapInd(i, p);
        upheap(p);
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
    void downheap(int i){
        int mini = i, l = left(i), r = right(i);
        if(l < H.size() and H[mini] > H[l]){
            mini = l;
        }
        if(r < H.size() and H[mini] > H[r]){
            mini = r;
        }

        if(mini != i){
            swapInd(i, mini);
            downheap(mini);
        }
    }

    // O(NlogN)
    vector<int> heapsort(){
        vector<int> data;
        while(!H.empty()){
            data.push_back(remove());
        }
        return data;
    }
};
int main(){
    heap h = heap();
    h.insert(34);
    h.insert(45);
    h.insert(22);
    h.insert(89);
    h.insert(76);
    vector<int> arr = h.heapsort();
    for(int i: arr) cout<<i<<" ";
}