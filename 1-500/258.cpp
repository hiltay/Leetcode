#include <iostream>
#include <vector>

using namespace std;
//class Solution {
//public:
//    int addDigits(int num) {
//        string n=to_string(num);
//        int r=0;
//        while (num>=10){
//            while (num!=0){
//                r+=num%10;
//                num/=10;
//            }
//            if (r<10) return r;
//            num=r;
//            r=0;
//        }
//
//        return num;
//
//    }
//};
//进阶：你可以不使用循环或者递归，在 O(1) 时间复杂度内解决这个问题吗？
class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};

int main() {

    Solution s = Solution();
    cout<<s.addDigits(10)<<endl;
    return 0;
}
