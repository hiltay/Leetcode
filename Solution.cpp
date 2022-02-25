#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class Solution {
public:
    vector<string> func(string s,vector<string> dict) {
        vector<string> arr;
        int segment_lenth = 0;
        for (int i = 0; i < dict.size(); i++) {
            segment_lenth = max(segment_lenth, (int) dict[i].size() / 3);
        }
        for (int i = s.size(); i > 0; i -= 3) {
            int l = i-segment_lenth*3>0?i-segment_lenth*3:0;
            int f = 0;
            while (l < i && f == 0) {
                string sub = s.substr(l, segment_lenth * 3);
                for (int index = 0; index < dict.size(); index++) {
                    if (sub == dict[index]) {
                        arr.push_back(sub);
                        s = s.substr(0, s.size() - sub.size());
                        i = l + 3;
                        f = 1;
                        break;
                    }
                }
                l += 3;
            }
        }
        vector<string> ret;
        vector<string>::reverse_iterator it;
        for(it=arr.rbegin();it!=arr.rend();it++){
            ret.push_back(*it);
        }
        return ret;

    }


};

int main() {
    Solution s = Solution();
    SetConsoleOutputCP(65001);
    string sentence="南京市长江大桥欢迎您";
    vector<string> dict={"南京", "南京市", "长江大桥", "大桥", "市长", "江大桥", "南京市", "欢迎您", "欢迎", "您"};
//　　　　待分词句子： sentence[]={"计算语言学课程有意思"}
//　　　　待分词句子： sentence[]={"南京市长江大桥欢迎您"}
//　　　　词表： dict[]={"计算", "计算语言学", "课程", "有", "意思"} 　
//　　　　词表： dict[]={"南京", "南京市", "长江大桥", "大桥", "市长", "江大桥", "南京市", "欢迎您", "欢迎", "您"} 　
    vector<string> ret = s.func(sentence,dict);
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << endl;
    return 0;
}
