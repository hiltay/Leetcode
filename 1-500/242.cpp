#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
    // O(n)
    // o(s.lenth)
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        // O(n)
        for(int i =0;i<s.size();i++){
            m[s[i]]++;
        }
        //O(n)
        for(int i=0;i<t.size();i++){
            if (m.find(t[i])!=m.end()){
                m[t[i]]--;
                if (m[t[i]]==0)
                    m.erase(t[i]);
            } else return false;
        }
        if (m.empty()) return true;
        else return false;
    }
};
int main() {

    Solution s = Solution();
    bool ret = s.isAnagram("anagamraaa","anagram");
    cout<<ret<<endl;
    //输入: s = "anagram", t = "nagaram"
    //输出: true
    return 0;
}
