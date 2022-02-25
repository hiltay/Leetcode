#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_set<char> st;
        if (s.size()!=t.size()) return false;

        for(int i=0;i<s.size();i++){
            auto it = m.find(s[i]);
            if (it!=m.end()){
                if (it->second!=t[i]) return false;
            } else if (st.find(t[i])==st.end()) {
                st.emplace(t[i]);
                m.emplace(make_pair(s[i],t[i]));
            } else return false;
        }
        return true;
    }
};
int main() {

    Solution s = Solution();
    bool ret = s.isIsomorphic("badc","baba");
    cout<<ret<<endl;
    return 0;
}
