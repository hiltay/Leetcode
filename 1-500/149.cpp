#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ret = 0;

        for(int i=0;i<points.size();i++){
            unordered_map<double,int> mp;
            int zero=0;
            for(int j=i+1;j<points.size();j++){
                // 求斜率，可能会有精度问题（本题暂时accepted）
                if (points[i][0]-points[j][0]==0) zero++;
                double k=(double)(points[i][1]-points[j][1])/(points[i][0]-points[j][0]);
                mp[k]++;
            }
            unordered_map<double,int>::iterator it;
            for(it=mp.begin();it!=mp.end();it++)
                ret= max(ret,it->second+1);
            ret= max(ret,zero+1);
        }
        return ret;
    }
};
int main() {

    Solution s = Solution();
    vector<vector<int>> points{{1,1},{2,2},{3,3}};
    int ret = s.maxPoints(points);
    cout<<ret<<endl;
//输入：points = [[1,1],[2,2],[3,3]]
//输出：3
    return 0;
}
