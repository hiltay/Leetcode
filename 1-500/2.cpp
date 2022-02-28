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
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        vector<int> arr;
//        int num,flag=0;
//        while (l1!= nullptr){
//            if (l2!= nullptr){
//                num=l1->val+l2->val+flag;
//                flag = calculate(num,arr);
//                l2=l2->next;
//            } else{
//                num=l1->val+flag;
//                flag = calculate(num,arr);
//            }
//            l1=l1->next;
//        }
//        while (l2!= nullptr){
//            num=l2->val+flag;
//            flag = calculate(num,arr);
//            l2=l2->next;
//        }
//        if (flag==1) arr.push_back(1);
//        ListNode* ret = createlinkedlist(arr,arr.size());
//        return ret;
//    }
//
//private:int calculate(int num,vector<int>& arr){
//        int ret=0;
//        if (num>=10) {
//            num%=10;
//            ret=1;
//        }
//        arr.push_back(num);
//        return ret;
//    }
//};

class Solution {
public: ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1), *pre = dummyHead;
        int t = 0;
        while (l1 != nullptr || l2 != nullptr || t != 0) {
            if (l1 != nullptr) {
                t += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                t += l2->val;
                l2 = l2->next;
            }
            pre->next = new ListNode(t % 10);
            pre = pre->next;
            t /= 10;
        }

        return dummyHead->next;
    }
};
int main() {

    Solution s = Solution();
    vector<int> arr1={9,9,9,9,9,9,9};
    vector<int> arr2={9,9,9,9};
    ListNode* head1 = createlinkedlist(arr1,7);
    ListNode* head2 = createlinkedlist(arr2,4);
    ListNode* ret = s.addTwoNumbers(head1,head2);
    printlinkedlist(ret);
    //输入：l1 = [2,4,3], l2 = [5,6,4]
    //输出：[7,0,8]
    //解释：342 + 465 = 807.
    return 0;
}
