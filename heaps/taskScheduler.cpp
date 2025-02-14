#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> ppi;
int leastInterval(vector<char>& tasks, int n) {
    priority_queue<int> pq;
    map<char, int> mappa;
    for(int task: tasks)
        mappa[task]++;
    for(pair<int, int> p: mappa)
        pq.push(p.second);
    int times = 0;
    while(!pq.empty()){
        int cycle = n+1;
        vector<int> remain;
        while(cycle and !pq.empty()){
            int maxFreq = pq.top(); pq.pop();
            if(maxFreq > 1)
                remain.push_back(maxFreq - 1);
            times++;
            cycle--;
        }
        for(int i: remain)
            pq.push(i);
        if(pq.empty())
            break;
        times += cycle;
    }
    return times;
}
int main(){
    int n, coolingInterval;
    char ele;
    vector<char> A;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter each CPU task: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        A.push_back(ele);
    }
    cout<<"Enter cpu interval before each task: ";
    cin>>coolingInterval;
    cout<<"Minimum no. of CPU intervals required: "<<leastInterval(A, coolingInterval)<<endl;
}