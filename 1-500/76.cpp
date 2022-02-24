#include <iostream>
#include <vector>
#include <string>

using namespace std;
// 滑动窗口
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> albums(52,0);
        vector<int> arr(52,0);
        for(int i=0;i<t.size();i++){
            if (isupper(t[i]))
                albums[t[i]-'A'+26]++;
            else albums[t[i]-'a']++;
        }
        int low=0,high=-1;
        int low_log,high_log,lenth=s.size()+1;
        while (high+1<s.size()||low<s.size()){
            if (same(albums,arr)) {
                if (high-low+1<lenth){
                    // 记录
                    low_log=low;high_log=high;
                    lenth= high_log-low_log+1;
                }
                // low向前
                if (isupper(s[low])) arr[s[low]-'A'+26]--;
                else arr[s[low]-'a']--;
                low++;
            } else{
                if (high+1<s.size()){
                    // high向前
                    high++;
                    if (isupper(s[high])) arr[s[high]-'A'+26]++;
                    else arr[s[high]-'a']++;
                } else // high到底
                    if (high-low+1<t.size()) break; // lenth小于t break
                    else low++;
            }


        }
        return lenth==s.size()+1?"":s.substr(low_log,lenth);
    }

private:
    bool same(vector<int>&albums,vector<int>& arr){
        for(int i=0;i<albums.size();i++){
            if (albums[i]>arr[i]) return false;
        }
        return true;
    }
};
int main() {

    Solution s = Solution();
    string str = s.minWindow("cabwefgewcwaefgcf","cae");
    cout<<str<<endl;
//输入：s = "ADOBECODEBANC"
//输出："BANC"
    return 0;
}
