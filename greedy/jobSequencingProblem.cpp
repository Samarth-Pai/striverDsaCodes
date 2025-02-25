#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct job{
    int id;
    int profit;
    int deadline;
};
static bool comp(job a, job b){
    return a.profit > b.profit;
}
vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
    vector<job> jobs;
    int n = id.size();
    for(int i = 0;i<n;i++){
        job j;
        j.id = id[i];
        j.deadline = deadline[i];
        j.profit = profit[i];
        jobs.push_back(j);
    }
    sort(jobs.begin(), jobs.end(), comp);
    int cnt = 0, totalProfit = 0, maxDeadline = jobs[0].deadline;
    for(job j: jobs){
        maxDeadline = max(maxDeadline, j.deadline);
    }
    vector<int> mappa(maxDeadline+1, -1);
    for(job j: jobs){
        for(int i = j.deadline;i>0;i--){
            if(mappa[i] == -1){
                mappa[i] = j.id;
                totalProfit += j.profit;
                cnt++;
                break;
            }
        }
    }
    return {cnt, totalProfit};
}
int main(){
    int n, ele;
    vector<int> id, deadline, profit;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter job id, deadline and profit of each jobs:"<<endl;
    for(int i = 0;i<n;i++){
        cin>>ele;
        id.push_back(ele);
        cin>>ele;
        deadline.push_back(ele);
        cin>>ele;
        profit.push_back(ele);
    }
    vector<int> ans = JobSequencing(id, deadline, profit);
    cout<<"Maximum job of "<<ans[0]<<" days can be done with the profit of "<<ans[1]<<endl;
}