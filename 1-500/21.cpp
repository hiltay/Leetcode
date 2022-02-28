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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*retlist=new ListNode(),*p=retlist;
        ListNode*cur1=list1;
        ListNode*cur2=list2;
        while (cur1!= nullptr||cur2!= nullptr){
            if (cur1== nullptr){
                p->next=new ListNode(cur2->val);
                cur2=cur2->next;
            } else if (cur2== nullptr){
                p->next=new ListNode(cur1->val);
                cur1=cur1->next;
            } else

            if (cur1->val>cur2->val){
                p->next=new ListNode(cur2->val);
                cur2=cur2->next;
            }
            else{
                p->next=new ListNode(cur1->val);
                cur1=cur1->next;
            }
            p=p->next;
        }
        return retlist->next;
    }
};
int main() {

    Solution s = Solution();
    vector<int> arr1 = {1, 2, 4};
    vector<int> arr2 = {1, 3, 4,};
    ListNode *head1 = createlinkedlist(arr1, 1);
    ListNode *head2 = createlinkedlist(arr2, 3);
    ListNode*ret=s.mergeTwoLists(head1, head2);
    printlinkedlist(ret);
    //输入：l1 = [1,2,4], l2 = [1,3,4]
    //输出：[1,1,2,3,4,4]
    return 0;
}
