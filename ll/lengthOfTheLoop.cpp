#include<iostream>
#include<map>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Brute approach: hashing
// TC: O(N 2logN)
// SC: O(N)
// int countNodesinLoop(Node *head) {
//     Node* temp = head;
//     int t = 1;
//     map<Node*, int> mpp;
//     while(temp){
//         if(mpp.find(temp)!=mpp.end())
//             return t - mpp[temp];
//         mpp[temp] = t++;
//         temp = temp->next;
//     }
//     return 0;
// }

// Optimal solution: Tortoise Hare algorithm
// TC: O(N)
// SC: O(1)
int countNodesinLoop(Node *head) {
    Node* slow = head, *fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            int cnt = 1;
            fast = fast->next;
            while(slow!=fast){  
                fast = fast->next;
                cnt++;
            }
            return cnt;
        }
    }
    return 0;
}

int main(){
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    head->next = n2;
    Node* n3 = new Node(3);
    n2->next = n3;
    Node* n4 = new Node(4);
    n3->next = n4;
    Node* n5 = new Node(5);
    n4->next = n5;
    n5->next = n2;

    cout<<"Length of the loop is: "<<countNodesinLoop(head)<<endl;
}