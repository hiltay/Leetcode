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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head== nullptr) return head;
        ListNode* dummy=new ListNode(-101,head),*pre=dummy;
        int dup=-101;
        while (head->next!= nullptr){
            if (pre->val!=head->val&&head->val!=head->next->val&&dup!=head->val){
                pre->next=head;
                pre=head;
            } else dup=head->val;
            head=head->next;
        }
        if (dup!=-101){
            if (dup==head->val) pre->next=head->next;
            else pre->next=head;
        }
        return dummy->next;
    }
};
int main() {

    Solution s = Solution();
    vector<int> arr = {1, 2, 3, 3, 3, 4};
    ListNode *head = createlinkedlist(arr, 6);
    ListNode*ret=s.deleteDuplicates(nullptr);
    printlinkedlist(ret);
    return 0;
}
