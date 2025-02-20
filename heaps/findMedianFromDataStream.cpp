#include<iostream>
#include<queue>
using namespace std;
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> box1;
    priority_queue<int, vector<int>, greater<int>> box2;
    
    void addNum(int num) {
        box1.push(num);
        box2.push(box1.top());
        box1.pop();
        if(box2.size()>box1.size()){
            box1.push(box2.top());
            box2.pop();
        }
    }
    
    double findMedian() {
        if(box1.size() == box2.size())
            return (box1.top()+box2.top())/2.0;
        else
            return (double)box1.top();
    }
};
int main(){
    MedianFinder medianFinder = MedianFinder();
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    cout<<medianFinder.findMedian()<<endl; // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    cout<<medianFinder.findMedian()<<endl; // return 2.0
}