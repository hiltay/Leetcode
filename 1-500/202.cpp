#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        int remainder;
        unordered_set<int> s;
        while (n!=1){
            int tmp=0;
            while (n!=0){
                remainder = n % 10 ;
                n/=10;
                tmp+=remainder*remainder;
            }
            if (s.find(tmp)==s.end()){
                n=tmp;
                s.emplace(n);
            } else return false;
        }
        return true;

    }
};
int main() {

    Solution s = Solution();
    bool ret = s.isHappy(2);
    cout<<ret<<endl;
//「快乐数」定义为：
//
//对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//如果这个过程 结果为1，那么这个数就是快乐数。
//输入：n = 19
//输出：true
//解释：
//1^2 + 9^2 = 82
//8^2 + 2^2 = 68
//6^2 + 8^2 = 100
//1^2 + 0^2 + 0^2 = 1
    return 0;
}
