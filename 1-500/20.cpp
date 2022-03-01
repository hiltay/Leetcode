#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            if (s[i]=='('||s[i]=='['||s[i]=='{'){
                stk.push(s[i]);
                continue;
            } else if (stk.empty()) return false;
            if (stk.top()=='('&&s[i]==')')
                stk.pop();
            else if (stk.top()=='['&&s[i]==']')
                stk.pop();
            else if (stk.top()=='{'&&s[i]=='}')
                stk.pop();
            else break;
        }
        if (stk.empty()) return true;
        else return false;
    }
};
int main() {

    Solution s = Solution();
    cout<<s.isValid("]")<<endl;
    // s 仅由括号 '()[]{}' 组成
    stack<int> ss;
    return 0;
}
