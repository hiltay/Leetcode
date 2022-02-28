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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //k 是一个正整数，它的值小于或等于链表的长度。
        ListNode*dummy=new ListNode(-101,head),*s=dummy,*cur=dummy;
        int pr=-1;
        while (cur!= nullptr){
            cur=cur->next;
            pr++;
        }
        while (pr>=k&&s->next&&s->next->next){
            ListNode*l=s->next,*r=l->next,*next=r->next,*pre=l;
            int len=2;
            while (k-len>=0){
                r->next=pre;
                pre=r;
                r=next;
                if (r)
                    next=next->next;
                len++;
            }
            s->next=pre;
            l->next=r;
            s=l;
            pr-=k;
        }
        ListNode*ret=dummy->next;
        delete dummy;
        return ret;

    }
};
int main() {

    Solution s = Solution();
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = createlinkedlist(arr, 5);
    ListNode*ret=s.reverseKGroup(head,4);
    printlinkedlist(ret);
    //输入：head = [1,2,3,4,5], k = 2
    //输出：[2,1,4,3,5]
    return 0;
}
