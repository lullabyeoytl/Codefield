/**
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int current_sum = nums[0];
        int current_min = nums[0];
        int max_sum = nums[0];
        if(n==1){
            return nums[0];
        }
        for(int i=1;i<n;i++){
            current_sum+=nums[i];
            if(current_sum<current_min){
                max_sum=max(current_sum,max_sum);
                max_sum=max(max_sum,current_sum-current_min);
                current_min=current_sum;
                continue;
            }
            max_sum=max(current_sum,max_sum);
            max_sum=max(max_sum,current_sum-current_min);
        }
        return max_sum;
    }
};