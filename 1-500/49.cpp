#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        unordered_map<char,int> mp;
//        vector<vector<string>> ret;
//        vector<string> emp;
//        for(auto it =strs.begin();it!=strs.end();){
//            if (it->empty()) {
//                emp.push_back("");
//                strs.erase(it);
//            } else it++;
//        }
//        if(!emp.empty()) ret.push_back(emp);
//        int i=0;
//        while (i<strs.size()){
//            if(strs[i]=="T") {
//                i++;
//                continue;
//            }
//
//            vector<string> ss;
//            ss.push_back(strs[i]);
//
//            for(int j=0;j<strs[i].size();j++){
//                mp[strs[i][j]]++;
//            }
//
//            int j=i+1;
//            while (j<strs.size()){
//                if (strs[j].size()!=strs[i].size()) {
//                    j++;continue;
//                }
//                auto tmp = mp;
//                for(int k=0;k<strs[j].size();k++){
//                    auto it = tmp.find(strs[j][k]);
//                    if (it!=mp.end()){
//                        if (--it->second==0)
//                            tmp.erase(it);
//                    } else break;
//                }
//                if (tmp.empty()) {
//                    ss.push_back(strs[j]);
//                    strs[j]="T"; // strs[i]
//                }
//                j++;
//            }
//            ret.push_back(ss);
//            mp.clear();
//            i++;
//        }
//        return ret;
//    }
//};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> map;
        for(const string& s: strs){
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }

        vector<vector<string>> res;
        for(const auto& p: map)
            res.push_back(p.second);
        return res;
    }
};
int main() {

    Solution s = Solution();
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ret = s.groupAnagrams(strs);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout<<ret[i][j]<<",";
        }
        cout<<"\n";
    }
//输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
    return 0;
}
