#include <iostream>
#include <vector>

using namespace std;
// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int current=0,ret=nums.size()+1,low=0,high=-1;
        while (low<nums.size()){
            if (high+1<nums.size() && current<target) current+=nums[++high];
            else current-=nums[low++];
            if (current>=target){
                ret= min(ret,high-low+1);
            }
        }
        if (ret==nums.size()+1) return 0;
        return ret;
    }
};
int main() {

    Solution s = Solution();
    vector<int> arr = {2,3,1,2,4,3};
    int ret = s.minSubArrayLen(7,arr);
    cout << ret<<endl;
    //输入：target = 7, nums = [2,3,1,2,4,3]
    //输出：2
    //解释：子数组 [4,3] 是该条件下的长度最小的子数组。
    return 0;
}
