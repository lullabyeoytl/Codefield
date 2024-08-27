/**
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 * 返回这三个数的和。假定每组输入只存在恰好一个解。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int target_sum = INT_MAX;
        int bigger = 1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            int i_target = target - nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == i_target) {
                    return target;
                }
                else if (sum < i_target) {
                    left++;
                    target_sum = min(target_sum, abs(sum + nums[i]-target));
                    if(target_sum == abs(sum + nums[i]-target)){
                        if(sum + nums[i] < target){
                            bigger = -1;
                        } else{
                            bigger = 1;
                            }
                    } 
                } 
                else {
                    right--;
                    target_sum = min(target_sum, abs(sum + nums[i]-target));
                     if(target_sum == abs(sum + nums[i]-target)){
                        if(sum + nums[i] < target){
                            bigger = -1;
                        } else{
                            bigger = 1;
                            }
                    } 
                }  
            }
        }
        return target_sum * bigger+target;
        
    }
};

//同样的是双指针，固定一个，考虑一下就知道只有代码中两中情形，双指针在这里是正确的