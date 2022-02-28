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
    ListNode* swapPairs(ListNode* head) {
        ListNode*dummy=new ListNode(-101,head),*s=dummy;
        while (s->next!= nullptr&&s->next->next!= nullptr){
            ListNode*l=s->next,*r=l->next,*next=r->next;
            s->next=r;
            r->next=l;
            l->next=next;

            s=l;
        }
        return dummy->next;
    }
};
int main() {

    Solution s = Solution();
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = createlinkedlist(arr, 1);
    ListNode*ret=s.swapPairs(head);
    printlinkedlist(ret);
    //输入：head = [1,2,3,4]
    //输出：[2,1,4,3]
    return 0;
}
