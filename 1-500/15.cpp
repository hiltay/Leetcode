#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
// reference:  https://github.com/liuyubobobo/Play-Leetcode/blob/master/0001-0500/0015-3Sum/cpp-0015/main1.cpp
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        unordered_map<int, int> counter;
        for(int i = 0 ; i < nums.size() ; i ++)
            counter[nums[i]] ++;

        vector<vector<int>> res;

        if(counter[0] >= 3)
            res.push_back({0, 0, 0});

        // Remove duplication
        sort(nums.begin(), nums.end());
        vector<int>::iterator iter = unique(nums.begin(), nums.end());
        nums.erase(iter, nums.end());

        for(int i = 0 ; i < nums.size() ; i ++)
            for(int j = i + 1 ; j < nums.size() ; j ++){

                if(nums[i] * 2 + nums[j] == 0 && counter[nums[i]] >= 2)
                    res.push_back({nums[i], nums[i], nums[j]});

                if(nums[i] + nums[j] * 2 == 0 && counter[nums[j]] >= 2)
                    res.push_back({nums[i], nums[j], nums[j]});

                int c = 0 - nums[i] - nums[j];
                if(c > nums[j] && counter[c] != 0)
                    res.push_back({nums[i], nums[j], c});
            }

        return res;
    }
};
int main() {

    Solution s = Solution();
    vector<int> nums = {3,0,-2,-1,1,2};
    vector<vector<int>> ret =s.threeSum(nums);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j]<<',';
        }
        cout<<endl;
    }
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
    return 0;
}
