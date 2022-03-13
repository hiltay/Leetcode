#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:bool validUtf8(vector<int>& data) {
        int i=0;
        while (i<data.size()){
            if (data[i]<0x80){
                i++;
            } else
            if (data[i]<0xe0){
                if(validate(data,i+1,1)) i+=2;
                else return false;
            } else
            if (data[i]<0xf0){
                if (validate(data,i+1,2)) i+=3;
                else return false;
            } else
            if (data[i]<0xf8){
                if (validate(data,i+1,3)) i+=4;
                else return false;
            }
            else return false;
        }
        return true;
}

private: bool validate(vector<int>& data,int start,int n){
        while (start<data.size()&&n>0){
            if (data[start]<0xc0&&data[start]>0x7f){
                start++;
                n--;
            } else return false;
        }
        if (n>0) return false;
        return true;
    }
};
int main() {
    //对于 n 字节的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，
    // 后面字节的前两位一律设为 10 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。
    
    Solution s = Solution();
    vector<int> arr= {235,140,4};
    cout<<s.validUtf8(arr)<<endl;
    return 0;
}
