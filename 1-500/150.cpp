#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(int i=0;i<tokens.size();i++){
            if (!isoperator(tokens[i]))
                stack.push(stoi(tokens[i]));
            else{
                int rop = stack.top();
                stack.pop();
                int lop = stack.top();
                stack.pop();
                if (tokens[i][0]=='+') stack.push(lop+rop);
                if (tokens[i][0]=='-') stack.push(lop-rop);
                if (tokens[i][0]=='*') stack.push(lop*rop);
                if (tokens[i][0]=='/') stack.push(lop/rop);
            }
        }
        return stack.top();
    }

private: bool isoperator(const string& str){
        if (str.size()!=1) return false;
        if (str[0]=='+'||str[0]=='-'||str[0]=='*'||str[0]=='/') return true;
        else return false;
    }
};
int main() {

    Solution s = Solution();
    vector<string> tokens = {"4","13","5","/","+"};
    cout<<s.evalRPN(tokens)<<endl;
    return 0;
}
