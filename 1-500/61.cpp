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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head== nullptr) return head;
        ListNode*dummy=new ListNode(0,head),*cur=dummy;
        int lenth=-1;
        while (cur!= nullptr){
            cur=cur->next;
            lenth++;
        }
        ListNode* ret= rotate(dummy,k,lenth);
        return ret->next;
    }

private: ListNode* rotate(ListNode* head,int k,int lenth){
        if (lenth<=k)
            k%=lenth;
        ListNode*slow=head,*fast=head;
        for(;k>0;k--){
            fast=fast->next;
        }
        while (fast->next!= nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        fast->next=head->next;
        head->next=slow->next;
        slow->next= nullptr;
        return head;

    }
};
int main() {

    Solution s = Solution();
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = createlinkedlist(arr, 1);
    ListNode*ret=s.rotateRight(head,1);
    printlinkedlist(ret);
    //输入：head = [1,2,3,4,5], k = 2
    //输出：[4,5,1,2,3]
    return 0;
}
