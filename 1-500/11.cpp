#include <iostream>
#include <vector>

using namespace std;

// 超时
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int low=0,high=height.size()-1,area=0;
//        while (low<high){
//            area = max(areas(low,high,height),area);
//            if(height[low]<height[high]){
//                for (int i=low+1;i<high;i++){
//                    if (height[i]>height[low]){
//                        area = max(areas(i,high,height),area);
//                    }
//                }
//                low++;
//            } else{
//                for (int i = high; i >low ; i--) {
//                    if (height[i]>height[high]){
//                        area = max(areas(low,i,height),area);
//                    }
//                }
//                high--;
//            }
//        }
//        return area;
//    }
//
//    int areas(int low,int high,vector<int>& height){
//        return (high-low)* min(height[low],height[high]);
//    }
//};

// 2、对撞指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0,high=height.size()-1,area=0;
        while (low<high){
            area = max(areas(low,high,height),area);
            if (height[low]<=height[high]){
                // low高度小于high高度 low++
                low++;
            } else high--; // 否则high--
        }
        return area;
    }

    int areas(int low,int high,vector<int>& height){
        return (high-low)* min(height[low],height[high]);
    }
};
int main() {

    Solution s = Solution();
    vector<int>nums = {1,8,6,2,5,4,8,3,7};
    int ret = s.maxArea(nums);
    cout << ret <<endl;
    return 0;
}
