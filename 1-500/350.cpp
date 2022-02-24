#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]++;
        }
        vector<int> ret;
        for(int i=0;i<nums2.size();i++){
            if (m[nums2[i]]>0){
                ret.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        return ret;
    }
};
int main() {

    Solution s = Solution();
    vector<int> nums1={4,9,5};
    vector<int> nums2={9,4,9,8,4};
    vector<int> ret = s.intersect(nums1,nums2);
    //输入：nums1 = [1,2,2,1], nums2 = [2,2]
    //输出：[2,2]
    for(int i=0;i<ret.size();i++){
        cout <<ret[i]<<endl;
    }
    return 0;
}
