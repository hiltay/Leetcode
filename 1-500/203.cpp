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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyhead=new ListNode(0,head),*pre=dummyhead;
        while (head!= nullptr){
            if (head->val==val){
                pre->next=head->next;
            } else
                pre=pre->next;
            head=head->next;
        }
        ListNode* ret =dummyhead->next;
        delete dummyhead;
        return ret;
    }
};
int main() {

    Solution s = Solution();
    vector<int> arr = {1, 2, 3, 5, 5};
    ListNode *head = createlinkedlist(arr, 5);
    ListNode* ret = s.removeElements(head,5);
    printlinkedlist(ret);
    return 0;
}
