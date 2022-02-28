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
    ListNode* insertionSortList(ListNode* head) {
        ListNode*dummy=new ListNode(5001);
        int len=0;
        while (head!= nullptr){
            ListNode*next=head->next;
            ListNode*pre=dummy;
            ListNode* node=new ListNode(5001);
            for(int i=0;i<len&&pre->next!= nullptr;i++){
                if (pre->next->val>head->val){
                    node->next=pre->next;
                    break;
                }
                pre=pre->next;
            }
            node->val=head->val;
            pre->next=node;
            head=next;
            len++;
        }
        ListNode* ret=dummy->next;
        delete dummy;
        return ret;
    }
};
int main() {

    Solution s = Solution();
    vector<int> arr = {1, 4, 3, 2, 5};
    ListNode *head = createlinkedlist(arr, 1);
    ListNode* ret=s.insertionSortList(head);
    printlinkedlist(ret);
    return 0;
}
