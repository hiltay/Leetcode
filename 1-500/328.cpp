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
//class Solution {
//public:
//    ListNode* oddEvenList(ListNode* head) {
//        if (head== nullptr) return head;
//        int ind=1;
//        ListNode L=ListNode(-1,head);
//        ListNode *even=&L,*cur=head,*odd=cur;
//        while (cur!= nullptr){
//            if (ind%2==1){
//                even->next=cur->next;
//                even=even->next;
//            } else{
//                odd->next=cur->next;
//                if (cur->next!= nullptr)
//                    odd=odd->next;
//            }
//            ind++;
//            cur=cur->next;
//        }
//        odd->next=L.next;
//        return head;
//
//    }
//};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy1 = new ListNode();
        ListNode* dummy2 = new ListNode();
        ListNode *p = dummy1, *q = dummy2, *r = head;
        while (r != nullptr) {
            p->next = r;
            r = r->next;
            p = p->next;
            if (r != nullptr) {
                q->next = r;
                r = r->next;
                q = q->next;
            }
        }
        p->next = dummy2->next;
        q->next = nullptr;
        delete dummy1, dummy2;
        return head;
    }
};
int main() {
    Solution s = Solution();
    vector<int> arr={2,1,3,5,6,4,7};
    ListNode* head = createlinkedlist(arr,7);
    ListNode* ret = s.oddEvenList(head);
    printlinkedlist(ret);
//输入: head = [2,1,3,5,6,4,7]
//输出: [2,3,6,7,1,5,4]
    return 0;
}
