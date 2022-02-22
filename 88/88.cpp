#include <iostream>
#include <vector>

using namespace std;
// 归并排序
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            if (i<m) tmp[i]=nums1[i];
            else tmp[i] = nums2[i-m];
        }
        int low=0,mid=m-1,high=m;
        for(int i =0;i<nums1.size();i++){
            if (low>mid){
                nums1[i] = tmp[high];
                high++;
            } else if (high>m+n-1){
                nums1[i] = tmp[low];
                low++;
            } else
            if (tmp[low]<tmp[high]){
                nums1[i] = tmp[low];
                low++;
            } else{
                nums1[i] = tmp[high];
                high++;
            }
        }
    }
};
int main() {

    vector<int> nums1 = {4,5,6,0,0,0},nums2 = {1,2,3};
    int m=3,n=3;
    Solution s = Solution();
    s.merge(nums1,m,nums2,n);
    for(int i =0;i<nums1.size();i++){
        cout<<nums1[i]<<endl;
    }
    // 使合并后的数组同样按 非递减顺序 排列。
//    输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//    输出：[1,2,2,3,5,6]
//    解释：需要合并 [1,2,3] 和 [2,5,6] 。
//    合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
    return 0;
}
