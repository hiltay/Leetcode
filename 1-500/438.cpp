#include <iostream>
#include <vector>
// 超时
using namespace std;
//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        vector<int> ret;
//        vector<int> ascii(256,0);
//        vector<int> ascii_copy(256,0);
//        for (int i = 0; i <(int)p.size() ; i++) {
//            ascii[p[i]]++;
//            ascii_copy[p[i]]++;
//        }
//        int low=0,high=-1;
//        while (low<s.size()){
//            if (high-low+1==(int)p.size()){
//                ret.push_back(low);
//                high=low;
//                low++;
//                ascii=ascii_copy;
//            }
//            if (high<(int)s.size() && ascii[s[high+1]]==0){
//                high=low;
//                low++;
//                ascii=ascii_copy;
//            } else if (high<(int)s.size() && ascii[s[high+1]]!=0){
//                high++;
//                ascii[s[high]]--;
//            }
//        }
//        return ret;
//
//    }
//};

// 滑动窗口
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;
        if(s.size() < p.size())
            return res;

        vector<int> freq_p(26, 0);
        for(char c: p)
            freq_p[c - 'a'] += 1;

        vector<int> freq_s(26, 0);
        int l = 0, r = -1; // Sliding window: s[l, r]
        while(r + 1 < s.size()){
            r ++;
            freq_s[s[r] - 'a'] ++;
            if(r - l + 1 > p.size())
                freq_s[s[l++] - 'a'] --;

            if(r - l + 1 == p.size() && same(freq_s, freq_p))
                res.push_back(l);
        }

        return res;
    }

private:
    bool same(const vector<int>& freq_s, const vector<int>& freq_p){
        for(int i = 0 ; i < 26; i ++)
            if(freq_s[i] != freq_p[i])
                return false;
        return true;
    }
};
int main() {

    Solution s = Solution();
    vector<int> ret = s.findAnagrams("abcebbbacd","abc");
    for (int i=0;i<ret.size();i++){
        cout << ret[i]<<endl;
    }
//输入: s = "abcebbbacd", p = "abc"
//输出: [0,6]
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
    return 0;
}
