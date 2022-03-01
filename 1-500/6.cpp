#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        auto it=s.begin();
        vector<vector<char>> arr(numRows);
        int row=0,col=0,f=0;
        while (it!=s.end()){

            arr[row].push_back(*it);
            if (row<numRows-1&&!f)
                row++;
            else
                f=1;
            if (f&&row>0){
                row--;
                col++;
            }
            if (row==0) f=0;
            it++;
        }
        string ret;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                ret.push_back(arr[i][j]);
            }
        }
        return ret;
    }
};
int main() {

    Solution s = Solution();
    cout<<s.convert("AB",1)<<endl;
//比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
//
//P   A   H   N
//A P L S I I G
//Y   I   R
// 输出："PAHNAPLSIIGYIR"
    return 0;
}
