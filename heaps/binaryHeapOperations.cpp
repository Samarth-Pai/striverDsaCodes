#include<iostream>
#include<climits>
using namespace std;
struct MinHeap {
    int *harr;
    int capacity;
    int heap_size;

    // Constructor for Min Heap
    MinHeap(int c) {
        heap_size = 0;
        capacity = c;
        harr = new int[c];
    }

    ~MinHeap() { delete[] harr; }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    void MinHeapify(int);
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
};

int main(){
    MinHeap h = MinHeap(7);
    h.insertKey(4);
    h.insertKey(2);
    cout<<h.extractMin()<<endl;
    h.insertKey(6);
    cout<<h.extractMin()<<endl;
    cout<<h.extractMin()<<endl;
}

//Function to extract minimum value in heap and then to store 
//next minimum value at first index.
int MinHeap::extractMin() 
{
    if(heap_size == 0) return -1;
    int temp = harr[0];
    int last = harr[heap_size-1];
    heap_size--;
    harr[0] = last;
    MinHeapify(0);
    return temp;
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    if(i >= heap_size) return;
    decreaseKey(i, INT_MIN);
    extractMin();
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k) 
{
    if(heap_size == capacity) return;
    heap_size++;
    decreaseKey(heap_size - 1, k);
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val) 
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}