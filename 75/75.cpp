#include <iostream>
#include <vector>
// https://leetcode-cn.com/problems/sort-colors
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // [2,0,2,1,1,0]
        int z = -1,t=nums.size();
        for (int i = 0; i < t;) {
            if (nums[i]==1){
                i++;
            } else if (nums[i]==2){
                swap(nums[i],nums[--t]);
            } else
                swap(nums[i++],nums[++z]);

        }
    }
};
int main() {
    vector<int> a = {2,0,2,1,1,0};
    Solution s =  Solution();
    s.sortColors(a);
    for (int i = 0; i < a.size(); i++) {
        cout<<a[i]<<endl;
    }
    return 0;
}
