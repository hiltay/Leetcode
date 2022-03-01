#include <iostream>
#include <stack>

using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string str;
        for(int i=0;i<path.size();i++){
            string sub=path.substr(i,path.size());
            int posl=sub.find('/');
            if (posl!=sub.npos){
                int posr=sub.find('/',posl+1);
                if (posr!=sub.npos)
                {
                    str=sub.substr(posl+1,posr-posl-1);
                    i+=posr-1;
                }
                else {
                    str=sub.substr(posl+1,sub.size());
                    i+=path.size();
                }

                if (str==".."&&!stk.empty())
                    stk.pop();
                else if (str!="."&&str!=".."&&!str.empty())
                    stk.push(str);
            }
        }
        string rev;
        stack<string> st;
        while (!stk.empty()){
            st.push(stk.top());
            stk.pop();
        }
        while (!st.empty()){
            rev.push_back('/');
            rev+=st.top();
            st.pop();
        }
        if (rev.empty()) rev.push_back('/');

        return rev;
    }

};
int main() {

    Solution s = Solution();
    cout<<s.simplifyPath("/home/")<<endl;
//输入：path = "/a/./b/../../c/"
//输出："/c"
    return 0;
}
