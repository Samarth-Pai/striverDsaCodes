#include<iostream>
#include<stack>
using namespace std;
class SortedStack{
public:
	stack<int> s;
	void sort();
};
void sortedInsert(stack<int> &s, int ele){
    if(s.empty() or s.top()<=ele){
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();

    sortedInsert(s, ele);

    s.push(temp);
}
void sortStack(stack<int> &s){
    if(s.empty() or s.size() == 1) return;
    int temp = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, temp);
}

// TC: O(N^2)
// SC: O(N) for recursive stack space
void SortedStack::sort(){
    sortStack(s);
}
void printStack(stack<int> s){
    if(s.empty()) return;
    int ele = s.top();
    s.pop();
    printStack(s);
    cout<<ele<<" ";
}

int main(){
    int n, ele;
    SortedStack st;
    cout<<"Enter the number of elements in the stack: ";
    cin>>n;
    cout<<"Enter the stack elments with top as last element: ";
    for(int i = 0;i < n;i++){
        cin>>ele;
        st.s.push(ele);
    }
    
    st.sort();

    cout<<"Stack after sorting: ";
    printStack(st.s);
    cout<<endl;
}