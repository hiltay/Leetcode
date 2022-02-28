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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        ListNode* dummyHead = new ListNode(-1), *pre = dummyHead;
        int t = 0;
        while (l1 != nullptr || l2 != nullptr || t != 0) {
            if (l1 != nullptr) {
                t += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                t += l2->val;
                l2 = l2->next;
            }
            pre->next = new ListNode(t % 10);
            pre = pre->next;
            t /= 10;
        }

        return reverseList(dummyHead->next);
    }

private:
    ListNode* reverseList(ListNode* head) {
        if (head== nullptr) return head;
        if (head->next== nullptr) return head;
        ListNode *pre= nullptr,*next=head->next;
        while (next!= nullptr){
            head->next=pre;
            pre=head;
            head=next;
            next=next->next;
        }
        head->next=pre;
        return head;
    }
};
int main() {

    Solution s = Solution();
    vector<int> arr1={7,2,4,3};
    vector<int> arr2={5,6,4};
    ListNode* head1 = createlinkedlist(arr1,4);
    ListNode* head2 = createlinkedlist(arr2,3);
    ListNode* ret = s.addTwoNumbers(head1,head2);
    printlinkedlist(ret);
    return 0;
}
