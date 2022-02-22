#include <iostream>
#include <vector>
// todo 未完成
using namespace std;
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ret(rains.size());
        vector<int> mark;

        // choice=[0,0,0,0,0,0]
        for (int i=0; i < rains.size(); i++) {
            if (rains[i]>0){
                // 下雨了

                mark.push_back(rains[i]);
                ret[i]=-1;
            } else{
                // 没下雨 可以抽一个区域的水
                // 1,2,0,2,3 如果后面与前面出现过的数字相同，就选他
                // 标记一下哪天没下雨
                ret[i]=mark[mark.size()-1];
                mark.pop_back();
            }
        }
        for (int i = 0; i < ret.size(); i++) {
            if (ret[i]!=-1){

            }
        }

        return ret;


    }
};
int main() {
    vector<int> rains = {1,2,0,1,3};
    Solution s = Solution();
    vector<int> ret = s.avoidFlood(rains);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] <<endl;
    }

    return 0;
}
