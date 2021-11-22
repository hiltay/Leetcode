#include <iostream>
#include <vector>

using namespace std;
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
