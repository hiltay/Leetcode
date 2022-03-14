#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string,int> mp;
        for(int i=0;i<list1.size();i++){
            mp.emplace(make_pair(list1[i],i));
        }
        int min_sum=list2.size()+list1.size();
        for (int i = 0; i < list2.size(); i++) {
            auto it=mp.find(list2[i]);
            if (it!=mp.end())
                min_sum= min(min_sum,it->second+i);
        }
        if (min_sum<list2.size()+list1.size()){
            for (int i = 0; i < list2.size(); i++) {
                auto it=mp.find(list2[i]);
                if (it!=mp.end()&&min_sum==it->second+i)
                    res.push_back(list2[i]);
            }
        }
        return res;
    }
};
int main() {
    //输入: list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
    //输出: ["Shogun"]
    //解释: 他们唯一共同喜爱的餐厅是“Shogun”。
    // ["vacag","KFC"]
    //["fvo","xrljq","jrl","KFC"]
    Solution s = Solution();
    vector<string> list1={"vacag","KFC"};
    vector<string> list2={"fvo","xrljq","jrl","KFC"};
    s.findRestaurant(list1,list2);
    return 0;
}
