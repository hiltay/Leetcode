#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
        string s;
        if(num==0) return "0";
        int neg=0;
        if (num<0) neg=1;
        int n=0,i=0;
        while (num!=0){
            n+=abs(num%7)* pow(10,i);
            num/=7;
            i++;
        }
        s=to_string(n);
        if (neg) s.insert(0,1,'-');
        return s;
    }
};
int main() {
    // 输入: num = 100
    //输出: "202"
    // x x x x x x
    // n*base^N
    Solution s = Solution();
    cout << s.convertToBase7(-75)<<endl;
    return 0;
}
