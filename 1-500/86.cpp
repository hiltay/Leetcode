#include <iostream>
#include <vector>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createlinkedlist(vector<int> nodes, int num) {
    if (num == 0) return nullptr;
    ListNode *head = new ListNode(nodes[0]);
    ListNode *now = head;
    for (int i = 1; i < num; i++) {
        now->next = new ListNode(nodes[i]);
        now = now->next;
    }
    return head;
}

void printlinkedlist(ListNode *head) {
    ListNode *now = head;
    while (now != nullptr) {
        cout << now->val;
        now = now->next;
    }
    cout << endl;
}
// 利用数组
//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        if (head== nullptr) return nullptr;
//        vector<int> arr;
//        int ind=201;
//        ListNode* cur=head;
//        while (cur!= nullptr){
//            arr.push_back(cur->val);
//            if (cur->val>=x) ind= min((int)arr.size()-1,ind);;
//            cur=cur->next;
//        }
//        if (ind==201) return head;
//        vector<int> sortedarr;
//        vector<int> tmparr;
//        for(int i=0;i<ind;i++){
//            sortedarr.push_back(arr[i]);
//        }
//        for(;ind<arr.size();ind++){
//            if (arr[ind]<x) sortedarr.push_back(arr[ind]);
//            else tmparr.push_back(arr[ind]);
//        }
//        for(int i=0;i<tmparr.size();i++){
//            sortedarr.push_back(tmparr[i]);
//        }
//        head = createlinkedlist(sortedarr,sortedarr.size());
//        return head;
//    }
//};

// 原地
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head== nullptr) return nullptr;
        ListNode* cur=head,*pre;
        ListNode L=ListNode(0,head);
        pre=&L;
        while (cur!= nullptr){
            if (cur->val>=x) break;
            pre=cur;
            cur=cur->next;
        }
        ListNode*start=pre;
        ListNode*s=cur;
        while (cur!= nullptr){
            if (cur->val<x){
                start->next=cur;
                start=start->next;
                pre->next=cur->next;
            } else{
                pre=cur;
            }
            cur=cur->next;
        }
        start->next=s;
        head=L.next;
        return head;
    }
};
int main() {

    Solution s = Solution();
    vector<int> n={1,4,3,2,5,2};
    ListNode* head= createlinkedlist(n,6);
    ListNode *ret = s.partition(head,3);
    printlinkedlist(ret);
    return 0;
}
