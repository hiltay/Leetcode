#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        int low=0,high=s.size()-1;
        // a,e,i,o,u

        while (low<high){
            if (isalpha(s[low])){
                if (isalpha(s[high])){
                    if (isvowel(s[low])){
                        if (isvowel(s[high])){
                            swap(s[low],s[high]);
                            low++;high--;
                        } else high--;
                    } else low++;
                }
                else high--;

            }
            else low++;
        }
        return s;
    }

    bool isvowel(char c){
        string vowel = "aeiou";
        for (int i=0;i<vowel.size();i++){
            if (vowel[i] == tolower(c))return true;
        }
        return false;
    }
};
int main() {

    Solution s = Solution();
    string str = s.reverseVowels("hello");
    cout << str<<endl;
//输入：s = "hello"
//输出："holle"
    return 0;
}
