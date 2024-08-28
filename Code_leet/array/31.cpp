/**
 * 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
 * 例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：
 * [1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
 * 整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。
 * 更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
 * 那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。
 * 如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列
 * （即，其元素按升序排列）。
 
 * 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
 * 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
 * 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，
 * 因为 [3,2,1] 不存在一个字典序更大的排列。
 * 给你一个整数数组 nums ，找出 nums 的下一个排列。
 * 必须 原地 修改，只允许使用额外常数空间。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nums_size = nums.size()-1;
        int end = nums_size; 
        while(end>0 && nums[end-1]>=nums[end]){
            end--;
        }
        if(end==0){
           std::reverse(nums.begin(),nums.end());
            return;
        }
        int start = end-1;
        int large_min = end;
        int minest=0;
        for(int i=start+1;i<=nums_size;i++){
            if(nums[i]>nums[start]){
                large_min = (nums[large_min]<nums[i])?large_min:i;
            }
        }
        int temp = nums[start];
        nums[start] = nums[large_min];
        nums[large_min] = temp;
        std::reverse(nums.begin()+start+1,nums.end());
    
    }
};

/**想清楚下一个到底怎么变换，之后模拟即可，end=0时直接reverse */