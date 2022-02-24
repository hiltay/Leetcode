#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s,r;
        for(int i=0;i<nums1.size();i++){
            s.emplace(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if (s.find(nums2[i])!=s.end()){
                r.emplace(nums2[i]);
            }
        }
        vector<int> ret;
//        unordered_set<int>::iterator it;
        for (auto it = r.begin(),end=r.end(); it != end; it++){
            ret.push_back(*it);
        }
        return ret;
    }
};
int main() {

    Solution s = Solution();
    vector<int> nums1={4,9,5};
    vector<int> nums2={9,4,9,8,4};
    vector<int> ret = s.intersection(nums1,nums2);
    for(int i=0;i<ret.size();i++){
        cout <<ret[i]<<endl;
    }
//输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出：[9,4]
//解释：[4,9] 也是可通过的
    return 0;
}
