#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        unordered_set<string> st;
        int i=0,j=0;
        for(int pos=j,lenth=0;j<=s.size()&&i<pattern.size();j++){
            if (s[j]==' '||j==s.size()){
                string sub_str = s.substr(pos,lenth);
                auto it = m.find(pattern[i]);
                if (it!=m.end()){
                    if (it->second!=sub_str) return false;
                } else if (st.find(sub_str)!=st.end()){
                    auto sti = st.find(sub_str);
                    if (*sti==sub_str) return false;
                }
                m.emplace(make_pair(pattern[i],sub_str));
                st.emplace(sub_str);
                pos=j+1;
                lenth=0;
                i++;
            } else lenth++;
        }
        if (j>s.size()&&i==pattern.size()) return true;
        else return false;
    }
};
int main() {

    Solution s = Solution();
    bool ret = s.wordPattern("aaa","aa aa aa aa");
    cout<<ret<<endl;
    //输入: pattern = "abba", str = "dog cat cat dog"
    //输出: true
    return 0;
}
