#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
typedef pair<int, ListNode*> lli;

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<lli, vector<lli>, greater<lli>> pq;
    ListNode *res = new ListNode(-1);
    ListNode *temp = res;
    for(ListNode *head: lists){
        if(head)
            pq.push({head->val, head->next});
    }
    while(!pq.empty()){
        lli curr = pq.top(); pq.pop();
        temp->next = new ListNode(curr.first);
        temp = temp->next;
        if(curr.second){
            pq.push({curr.second->val, curr.second->next});
        }
    }
    return res->next;
}

int main(){
    int n, m, ele;
    vector<ListNode*> lists;
    cout<<"Enter the no. of linked lists with each rows in sorted order: ";
    cin>>n;
    for(int i = 0;i<n;i++){
        ListNode *head = new ListNode(-1);
        ListNode *temp = head;
        cout<<"Enter linked list "<<i<<" size: ";
        cin>>m;
        cout<<"Enter linked list "<<i<<" elements: ";
        for(int j = 0;j<m;j++){
            cin>>ele;
            temp->next = new ListNode(ele);
            temp = temp->next;
        }
        lists.push_back(head->next);
    }
    ListNode *newHead = mergeKLists(lists);
    ListNode *temp = newHead;
    cout<<"Merged linked list: ";
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}