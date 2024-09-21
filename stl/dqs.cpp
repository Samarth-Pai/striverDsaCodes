#include<iostream>
#include<deque>
using namespace std;
int main(){
    // all operations are same as of list, the difference is that list provides random access to element whereas dequeue provides sequential access. due to wich the elements of a dequeue can be accessed directly through for loops
    deque<int>dq;
    dq.push_back(10);
    dq.emplace_back(20);
    dq.push_front(40);
    dq.emplace_front(50);

    dq.pop_back();
    dq.pop_front();
    for()
}