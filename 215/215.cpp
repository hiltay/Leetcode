#include <iostream>
#include <vector>

using namespace std;
// 快速选择
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low=0,high=(int)nums.size()-1;
        while (low<high){
            int index = partition(nums,low,high);
            if (index==nums.size()-k){
                return nums[index];
            }
            if (index < nums.size()-k){
                // 向右快选
                low=index+1;
            } else high=index-1; // 向左快选
        }
        return nums[low];
    }

    int partition(vector<int>& nums,int low,int high){
        int piv = nums[low];
        while (low<high){
            while (low<high&&nums[high]>=piv){
                high--;
            }
            nums[low] = nums[high];
            while (low<high&&nums[low]<=piv){
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = piv;
        return low;
    }
};
int main() {
    Solution s = Solution();
    vector<int> arr = {3,2,1,5,6,4};
    int ret = s.findKthLargest(arr,2);
    cout << ret << endl;
    // 输入: [3,2,1,5,6,4] 和 k = 2
    // 输出: 5
    return 0;
}
