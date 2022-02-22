#include <iostream>
#include <vector>

using namespace std;
// 1、全排列，超时
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& numbers, int target) {
//        vector<int> ret(2);
//        for (int i = 0; i < numbers.size(); i++) {
//            for (int j = i+1; j < numbers.size(); j++) {
//                if (numbers[i]+numbers[j]==target){
//                    ret[0] = i+1;
//                    ret[1] = j+1;
//                    return ret;
//                }
//            }
//        }
//        return ret;
//    }
//};

// 2、二分 O(nlogn) 通过
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& numbers, int target) {
//        vector<int> ret(2);
//        int low,high=numbers.size()-1;
//        for (int i = 0; i <= high; i++) {
//            low = i+1;
//            while (low<=high){
//                int mid = (low+high)/2;
//                if (target-numbers[i]==numbers[mid]) {
//                    ret[0] = i+1;
//                    ret[1] = mid+1;
//                    return ret;
//                }
//                if (target-numbers[i]<numbers[mid]) high=mid-1;
//                else {
//                    low=mid+1;
//                }
//            }
//
//            high=numbers.size()-1;
//        }
//        return ret;
//    }
//};

// 3、对撞指针 O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret = {0,0};
        for (int i = 0,j=numbers.size()-1; i < j; ) {
            if (numbers[i]+numbers[j] == target) {
                return vector<int> {i+1,j+1};
            }
            if (numbers[i]+numbers[j]<target) i++;
            else j--;
        }
        return ret;
    }
};
int main() {

    Solution s = Solution();
    vector<int> numbers = {5,25,75};
    vector<int> ret = s.twoSum(numbers,100);
    cout<< ret[0] << ret[1] << endl;
//输入：numbers = [2,7,11,15], target = 9
//输出：[1,2]
//解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
    return 0;
}
