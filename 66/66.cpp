#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[digits.size()-1]<9){
            digits[digits.size()-1]++;
            return digits;
        }
        for (int i = (int)digits.size()-1; i >= 0; i--) {
            if (digits[i]<9) {
                digits[i]++;
                return digits;
            } else{
                digits[i]=0;
            }
        }
        if (digits[digits.size()-1]==0){
            vector<int> ret(digits.size()+1);
            ret[0]++;
            return ret;
        }
        return digits;
    }
};
int main() {
    Solution s = Solution();
    vector<int> a = {0,0};
    vector<int> ret = s.plusOne(a);
    for (int i = 0; i < ret.size(); i++) {
        cout<<ret[i]<<endl;
    }

    return 0;
}
