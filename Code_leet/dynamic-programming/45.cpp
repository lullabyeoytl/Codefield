/**
 * 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
 * 每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
 * 0 <= j <= nums[i] 
 * i + j < n
 * 返回到达 nums[n - 1] 的最小跳跃次数。
 * 生成的测试用例可以到达 nums[n - 1]。
 */

#include <bits/stdc++.h>
using namespace std;
/* dp only o(n^2)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int min_jump = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i) {
                    min_jump = min(min_jump, dp[j] + 1);
                }
            }
            dp[i] = min_jump;
        }
        return dp[n - 1];
    }
};
*/
/*
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=i;
        }
        int count=0;int searchpoint = n-1;
        while(searchpoint>0){
            int end = find(nums,searchpoint);
            count++;
            searchpoint = end;
        }
        return count;
        
    }

    int find(vector<int>& nums,int end){
        for(int i=0;i<end;i++){
            if(nums[i]>=end){
                return i;
            }
        }
        return -1;
    }
};
*/
