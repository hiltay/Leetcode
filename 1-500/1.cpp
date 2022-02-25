#include <iostream>
#include <vector>
#include <unordered_map>

// https://leetcode-cn.com/problems/two-sum/
using namespace std;
// O(n^2)
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        for (int i=0;i<nums.size();i++){
//            for (int j = i+1;j<nums.size();j++){
//                if (nums[i]+nums[j]==target) return vector<int> {i,j};
//
//            }
//
//        }
//        return vector<int> {};
//    };
//};

// 先放入map后查找
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> ret;
//        unordered_map<int,int> mp;
//        for(int i=0;i<nums.size();i++){
//            auto r =mp.emplace(make_pair(nums[i],i));
//            if (!r.second&&nums[i]*2==target){
//                // 如果查找map中存在相同key，并且key*2==target
//                auto it = mp.find(nums[i]);
//                ret.push_back(it->second);
//                ret.push_back(i);
//                return ret;
//            }
//        }
//        unordered_map<int,int>::iterator it;
//        for(it=mp.begin();it!=mp.end();it++){
//            auto it2=mp.find(target-it->first);
//            if (it2!=mp.end()&&it2->first!=it->first){
//                ret.push_back(it->second);
//                ret.push_back(it2->second);
//                return ret;
//            }
//        }
//        return ret;
//    };
//};

// 边找边插入
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            auto it = mp.find(target-nums[i]);
            if (it!=mp.end()&&it->first+nums[i]==target){
                ret.push_back(it->second);
                ret.push_back(i);
                return ret;
            } else mp.emplace(make_pair(nums[i],i));
        }
        return ret;
    };
};


int main() {
    // 输入：nums = [2,7,11,15], target = 9
    // 输出：[0,1]
    vector<int> nums = {2,4,11,3};
    Solution s = Solution();
    vector<int> ret = s.twoSum(nums,6);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] <<endl;
    }
    return 0;
}
