#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    static bool cmp(pair<char, int> a , pair<char,int> b)
    {
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> m;

        for(int i=0;i<s.size();i++){
            auto it=m.find(s[i]);
            if (it!=m.end()){
                it->second++;
            } else{
                m.emplace(make_pair(s[i],1));
            }
        }
        string ret;
        vector<pair<char,int>> vec;
        unordered_map<char,int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            vec.emplace_back(*it);
        }
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i<vec.size();){
            if (vec[i].second--!=0) ret.push_back(vec[i].first);
            else i++;
        }
        return ret;
    }
};
int main() {

    Solution s = Solution();
    string ret = s.frequencySort("tree");
    cout<<ret<<endl;
//输入:
//"tree"
//
//输出:
//"eert"
//
//解释:
//'e'出现两次，'r'和't'都只出现一次。
//因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。

    return 0;
}
