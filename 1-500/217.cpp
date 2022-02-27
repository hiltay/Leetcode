#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            if (st.find(nums[i])!=st.end()) return true;
            else st.emplace(nums[i]);
        }
        return false;
    }
};
int main() {

    Solution s = Solution();
    vector<int> nums = {1,2,3,4};
    cout<<s.containsDuplicate(nums)<<endl;
//输入：nums = [1,2,3,1]
//输出：true
    return 0;
}
