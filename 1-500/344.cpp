#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int low=0,high=s.size()-1;
        while (low<high){
            swap(s[low],s[high]);
            low++;high--;
        }
    }
};
int main() {

    Solution s = Solution();
    vector<char>c ={'h','e','l','l','o'};
    s.reverseString(c);
    for (int i = 0; i < c.size(); ++i) {
        cout<< c[i];
    }
    cout<<endl;


//输入：s = ["h","e","l","l","o"]
//输出：["o","l","l","e","h"]
    return 0;
}
