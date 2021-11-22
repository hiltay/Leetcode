#include <iostream>
#include "vector"

using namespace std;
// v1
/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> NonZeroElements;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]){
                NonZeroElements.push_back(nums[i]);
            }
        }
        for (int i = 0; i < NonZeroElements.size(); i++) {
            nums[i]= NonZeroElements[i];
        }
        for (int i =NonZeroElements.size();i<nums.size();i++){
            nums[i]=0;
        }

    }
};
 */

// v2
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]){
                if (i!=j)
                    swap(nums[j++],nums[i]);
                else
                    j++;
            }
        }

    }
};

int main() {

    vector<int> a = {2,1,0,0,3};
    Solution().moveZeroes(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] <<endl;
    }

    return 0;
}

