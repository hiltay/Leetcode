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
    ListNode* reorderList(ListNode* head) {
        ListNode*dummy=new ListNode(0,head);
        ListNode* slow=dummy,*fast=dummy,*mid;
        int num=-1;
        while (fast&&fast->next!= nullptr){
            fast=fast->next->next;
            slow=slow->next;
            num++;
        }
        int ev=0;
        if (fast){
            num++;
            ev=1;
        }

        if (num<=0) return head;
        mid=slow;
        slow=dummy->next;
        while (num){
            fast=mid;
            int n=num;
            while (n){
                fast=fast->next;
                n--;
            }
            fast->next=slow->next;
            slow->next=fast;
            slow=fast->next;
            num--;
        }
        if (ev){
            mid=mid->next;
        }
        mid->next= nullptr;
        return head;
    }
};
int main() {

    Solution s = Solution();
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = createlinkedlist(arr, 2);
    ListNode *ret=s.reorderList(head);
    printlinkedlist(ret);
    return 0;
}
