#include<iostream>
#include<vector>
using namespace std;
// class heap{
//     vector<int> H;
//     public:
//     heap(){}
//     heap(vector<int> &arr){
//         for(int i: arr)
//             insert(i);
//     }

//     int parent(int i){
//         return (i - 1) / 2;
//     }

//     int left(int i){
//         return i * 2 + 1;
//     }

//     int right(int i){
//         return i * 2 + 2;
//     }

//     void maxHeapify(int i){
//         int l = left(i), r = right(i), mini = i;
//         if(l < H.size() and H[l] > H[i]){
//             mini = l;
//         }
//         if(r < H.size() and H[r] > H[i]){
//             mini = r;
//         }
//         if(mini != i){
//             swap(H[mini], H[i]);
//             maxHeapify(mini);
//         }
//     }

//     void upheap(int i){
//         int p = parent(i);
//         if(H[p] < H[i]){
//             swap(H[p], H[i]);
//             upheap(p);
//         }
//     }

//     void insert(int val){
//         H.push_back(val);
//         upheap(H.size() - 1);
//     }
// }

void maxHeapify(vector<int> &arr, int i){
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int maxi = i;
    if(l < arr.size() and arr[l] > arr[maxi])
        maxi = l;
    if(r < arr.size() and arr[r] > arr[maxi])
        maxi = r;
    if(maxi != i){
        swap(arr[maxi], arr[i]);
        maxHeapify(arr, maxi);
    }
}

void convertMinToMaxHeap(vector<int> &arr, int N){
    for(int i = (N - 2)/2;i>=0;i--){
        maxHeapify(arr, i);
    }
}

int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter heap size: ";
    cin>>n;
    cout<<"Enter min heap array: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    convertMinToMaxHeap(arr, n);
    cout<<"Max heap array: ";
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}