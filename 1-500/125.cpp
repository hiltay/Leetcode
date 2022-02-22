#include <iostream>
#include <vector>
#include <string>

using namespace std;
// 对撞指针
class Solution {
public:
    bool isPalindrome(string s) {
        int low=0,high=s.size()-1;
        while (low<high){
            if (isalnum(s[low])){
                if (isalnum(s[high])){
                    if (tolower(s[low])== tolower(s[high])){
                        low++;
                        high--;
                    } else return false;

                } else high--;
            } else low++;
        }
        return true;
    }
};
int main() {

    Solution s = Solution();
    bool ret = s.isPalindrome("A man, a plan, a canal: Panama");
    cout << ret <<endl;
//输入: "A man, a plan, a canal: Panama"
//输出: true
//解释："amanaplanacanalpanama" 是回文串
    return 0;
}
