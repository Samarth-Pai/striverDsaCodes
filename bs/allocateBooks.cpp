#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long arrSum(vector<int> arr){
    long sum = 0;
    for(int i: arr) sum+=i;
    return sum;
}

int countStudents(vector<int> arr, int n, int pages){
    int stdNo = 1, stdPages = 0;
    for(int i=0;i<n;i++){
        if(arr[i]+stdPages<=pages)
            stdPages+=arr[i];
        else{
            stdNo++;
            stdPages = arr[i];
        }
    }
    return stdNo;
}

// Brute approach
// TC: O((sum-max+1)*n)
// SC: P(1)
// int findPages(vector<int> arr, int n, int m) {
//     if(m>n) return -1;
//     int low = *min(arr.begin(), arr.end()), cntStudents;
//     long high = arrSum(arr);
//     for(int pages = low;pages<high; pages++){
//         cntStudents = countStudents(arr, n, pages);
//         if(cntStudents==m)
//             return pages;
//     }
//     return -1;
// }

// Optimal solution
// TC: O(log_2(sum-max+1)*n)
// SC: O(1)
int findPages(vector<int> arr, int n, int m) {
    if(m>n) return -1;
    int low = *max_element(arr.begin(), arr.end()), cntStudents, mid;
    long high = arrSum(arr);
    while(low<=high){
        mid = (low + high)/2;
        cntStudents = countStudents(arr, n, mid);
        if(cntStudents>m)   
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main(){
    int ele, n, m;
    vector<int> books;
    cout<<"Enter the number of books: ";
    cin>>n;
    cout<<"Enter number of pages of each books: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        books.push_back(ele);
    }

    cout<<"Enter the number of students: ";
    cin>>m;
    cout<<"Minimum of pages are "<<findPages(books, n, m)<<endl;
}