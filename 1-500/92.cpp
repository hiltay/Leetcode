#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 不使用虚拟头结点，需要对从1开始反转的情况做特殊处理；需要对left==right做判断
//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right) {
//        if (left==right) return head;
//        int current=1;
//        ListNode*pre,*start=head,*begin=head;
//        int f=0;
//        while(head!= nullptr&&current<=right){
//            ListNode*next = head->next;
//            if (current<left){
//                start=head;
//            } else if(current==left){
//                pre=head;
//                if (start==pre) f=1;
//            } else{
//                head->next=pre;
//                pre=head;
//            }
//            head=next;
//            current++;
//        }
//        if (f){
//            start->next=head;
//            return pre;
//        }
//        start->next->next=head;
//        start->next=pre;
//        return begin;
//    }
//};

// 使用虚拟头结点，不需要对从1开始反转的情况做特殊处理；不需要对left==right做判断
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int current=1;
        ListNode fakenode=ListNode(-1);
        ListNode*pre,*start,*begin=&fakenode;
        begin->next=head;
        start=begin;
        while(head!= nullptr&&current<=right){
            ListNode*next = head->next;
            if (current<left)
                start=head;
            else if(current==left)
                pre=head;
            else{
                head->next=pre;
                pre=head;
            }
            head=next;
            current++;
        }
        start->next->next=head;
        start->next=pre;
        return begin->next;
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
    vector<int> n={1,2,3,4,5};
    ListNode *head = createlinkedlist(n,5);
    printlinkedlist(head);
    ListNode* ret = s.reverseBetween(head,3,4);
    printlinkedlist(ret);

//输入：head = [1,2,3,4,5], left = 2, right = 4
//输出：[1,4,3,2,5]
    return 0;
}
