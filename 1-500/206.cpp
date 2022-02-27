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

class Solution {
public:
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

    return 0;
}
