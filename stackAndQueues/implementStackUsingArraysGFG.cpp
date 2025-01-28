#include<iostream>
using namespace std;
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
void MyStack ::push(int x) {
    if(top==999) return;
    top++;
    arr[top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    if(top == -1) return -1;
    return arr[top--];
}
int main(){
    MyStack s;
    s.push(2);
    s.push(3);
    cout<<s.pop()<<endl;
    s.push(4);
    cout<<s.pop()<<endl;
}