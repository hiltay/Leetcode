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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre= nullptr,*current=head;
        while (current!= nullptr){
            if (pre!= nullptr)
                if (pre->val==current->val){
                    pre->next=current->next;
                    ListNode* del=current;
                    current=current->next;
                    delete del;
                    continue;
                }
            pre=current;
            current=current->next;
        }
        return head;
    }
};

ListNode* createlinkedlist(vector<int> nodes,int num){
    if (num==0) return nullptr;
    ListNode*head=new ListNode(nodes[0]);
    ListNode* now = head;
    for(int i=1;i<num;i++){
        now->next = new ListNode(nodes[i]);
        now=now->next;
    }
    return head;
}

void printlinkedlist(ListNode* head){
    ListNode *now=head;
    while (now!= nullptr){
        cout<<now->val;
        now=now->next;
    }cout<<endl;
}
int main() {

    Solution s = Solution();
    vector<int> n={1,2,3,4,5,6,6,6,6};
    ListNode *head = createlinkedlist(n,9);
    printlinkedlist(head);
    ListNode* ret = s.deleteDuplicates(head);
    printlinkedlist(ret);
    return 0;
}
