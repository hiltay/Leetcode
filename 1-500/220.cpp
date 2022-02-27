#include <iostream>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> st;
        for(int i=0;i<nums.size();i++){
            if (st.lower_bound((long long)nums[i]-(long long)t)!=st.end()&&
            *st.lower_bound((long long)nums[i]-(long long)t)<=(long long)nums[i]+(long long)t)
                return true;
            st.emplace(nums[i]);

            if (st.size()==k+1)
                st.erase(nums[i-k]);
        }
        return false;
    }
};
int main() {

    Solution s = Solution();
    vector<int> nums = {1,2,3,1};
    cout<<s.containsNearbyAlmostDuplicate(nums,3,0)<<endl;
    return 0;
}
