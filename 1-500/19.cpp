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
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        int lenth=-1;
//        ListNode*dummy=new ListNode(-1,head);
//        ListNode*slow=dummy,*fast=dummy;
//        while (slow!= nullptr){
//
//            if (fast!= nullptr){
//                fast=fast->next;
//                lenth++;
//            }
//
//            if (fast== nullptr){
//                if (lenth-n>0){
//                    slow=slow->next;
//                    lenth--;
//                } else break;
//
//            }
//        }
//        ListNode*del=slow->next;
//        slow->next=del->next;
//        delete del;
//
//        del=dummy->next;
//        delete dummy;
//        return del;
//    }
//};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head== nullptr) return head;
        ListNode*dummy=new ListNode(-1,head);
        ListNode*slow=dummy,*fast=dummy;
        while (fast!= nullptr){
            if (n+1>0){
                fast=fast->next;
                n--;
            } else{
                fast=fast->next;
                slow=slow->next;
            }
        }
        ListNode*del=slow->next;
        slow->next=del->next;
        delete del;

        del=dummy->next;
        delete dummy;
        return del;
    }
};
int main() {

    Solution s = Solution();
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = createlinkedlist(arr, 5);
    ListNode*ret=s.removeNthFromEnd(head,5);
    printlinkedlist(ret);
    //输入：head = [1,2,3,4,5], n = 2
    //输出：[1,2,3,5]
    return 0;
}
