#include <iostream>
#include <vector>

using namespace std;

//思路，快慢指针
//题目明确是升序排列的。
//快指针遍历，慢指针代表当前值； 遇到不相等元素时，如果i和j相差超过2说明中间肯定有重复的元素，慢指针自增1然后更新数组元素。
//
//如果没有超过2说明没有重复，单纯让慢指针自增1，不更新数组。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int j=0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]!=nums[j]){
                if (i-j>1)
                    nums[++j]=nums[i];
                else
                    j++;
            }
        }
        return j+1;

    }
};

int main() {
    vector<int> a ={1,2};
    Solution s = Solution();
    int ret = s.removeDuplicates(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] <<endl;

    }
    cout << ret <<endl;
    return 0;
}
