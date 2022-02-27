#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
// O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size()<2) return false;
        unordered_set<int> st;
        int low=0,high=1;
        st.emplace(nums[low]);
        while (high<nums.size()){
            if (high-low>k){
                st.erase(nums[low]);
                low++;
            } else{
                if (st.find(nums[high])!=st.end()) return true;
                st.emplace(nums[high]);
                high++;
            }
        }
        return false;
    }
};
int main() {

    Solution s = Solution();
    vector<int> nums = {1,2,3,4};
    cout<<s.containsNearbyDuplicate(nums,3)<<endl;
//输入：nums = [1,2,3,1], k = 3
//输出：true
    return 0;
}
