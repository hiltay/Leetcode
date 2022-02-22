#include <iostream>
#include <vector>

// https://leetcode-cn.com/problems/two-sum/
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0;i<nums.size();i++){
            for (int j = i+1;j<nums.size();j++){
                if (nums[i]+nums[j]==target) return vector<int> {i,j};

            }

        }
        return vector<int> {};
    };
};



int main() {
    // 输入：nums = [2,7,11,15], target = 9
    // 输出：[0,1]
    vector<int> nums = {2,7,11,15};
    Solution s = Solution();
    vector<int> ret = s.twoSum(nums,9);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] <<endl;
    }
    return 0;
}
