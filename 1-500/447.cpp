#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        for(int i=0;i<points.size();i++){
            unordered_map<int,int> mp;
            for(int j=0;j<points.size();j++)
                if (i!=j){
                    int dis =(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+
                            (points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                    mp[dis]++;
                }
            for(auto it=mp.begin();it!=mp.end();it++)
                if (it->second>=2)
                    ret+=(it->second)*(it->second-1); // 排列数An2
        }
        return ret;
    }
};
int main() {

    Solution s = Solution();
    vector<vector<int>> points = {{0,0},{1,0},{2,0}};
    cout << s.numberOfBoomerangs(points)<<endl;
//输入：points = [[0,0],[1,0],[2,0]]
//输出：2
//解释：两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
    return 0;
}
