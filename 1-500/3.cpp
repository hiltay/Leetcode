#include <iostream>
#include <vector>
#include <string>

using namespace std;
// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(256,0);
        int low=0,high=-1,ret=0;
        while (low<s.size()){
            if (high+1<s.size()&& arr[s[high+1]]==0){

                arr[s[++high]]++;
            } else arr[s[low++]]--;

            ret = max(high-low+1,ret);

        }
        return ret;
    }
};
int main() {

    Solution s = Solution();
    int ret = s.lengthOfLongestSubstring("pwwkew");
    cout << ret <<endl;
// 输入: s = "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
    return 0;
}
