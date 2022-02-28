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
    bool isPalindrome(ListNode* head) {
        ListNode*dummy=new ListNode(0,head);
        ListNode*slow=dummy,*fast=dummy;
        while (fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if (fast)
            slow=slow->next;

        ListNode* mid=new ListNode(0,slow);
        mid->next=reverse(mid->next);
        ListNode* dm1=dummy;
        while (mid!= nullptr){
            if (dm1->val!=mid->val)
                return false;
            dm1=dm1->next;
            mid=mid->next;
        }
        delete dummy;
        delete mid;
        return true;
    }

private:  ListNode* reverse(ListNode* head) {
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
    vector<int> arr = {1, 2, 3, 3, 1};
    ListNode *head = createlinkedlist(arr, 2);
    bool ret =s.isPalindrome(head);
    cout<<ret<<endl;
    return 0;
}
