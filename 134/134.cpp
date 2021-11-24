#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> r(gas.size());
        int total = 0;
        for (int i = 0; i < gas.size(); i++) {
            r[i]=gas[i]-cost[i];
            total+=gas[i]-cost[i];
        }
        if (total<0) return -1;
        int start=0;
        total=0;
        for (int i = 0; i < gas.size(); i++) {
            total+=r[i];
            if (total<0){
                total=0;
                start=i+1;
            }

        }
        return start;
    }

};
int main() {
    vector<int> gas = {5,1,2,3,4};
    vector<int> cost = {4,4,1,5,1};
    Solution s = Solution();
    int ret = s.canCompleteCircuit(gas,cost);
    cout << ret <<endl;

    return 0;
}
