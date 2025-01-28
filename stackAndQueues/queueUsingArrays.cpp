#include<iostream>
using namespace std;
class qImp{
    public:
    int start = -1, end = -1, arrSize = 0;
    int siz = 10;
    int q[10];
    // TC: O(1)
    void push(int n){
        if(arrSize == 0){
            start = 0;
            end = 0;
        }
        else end = (end + 1)%siz;
        q[end] = n;
        arrSize++;
    }
    // TC: O(1)
    void pop(){
        if(arrSize == 0) return;
        if(arrSize == 1){
            start = -1;
            end = -1;
        }
        else{
            start = (start + 1)%siz;
        }
        arrSize--;
    }
    // TC: O(1)
    int top(){
        if(arrSize==0) return -1;
        return q[start];
    }
    // TC: O(1)
    int size(){
        return arrSize;
    }
};
int main(){
    qImp q;
    q.push(10);
    q.push(20);
    q.pop();
    cout<<q.top()<<endl;
    q.push(30);
    q.push(90);
    q.push(20);
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.top()<<endl;
}