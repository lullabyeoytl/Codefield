#include <stdio.h>
#include <vector>
/**
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
 * 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
 * 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你不触动警报装置的情况下 ，
 * 一夜之内能够偷窃到的最高金额。
*/
class Solution {
public:
    int dp[2][105];
    int rob(std::vector<int>& nums) {
        int size=nums.size();
        for(int i=1;i<=size;i++){
            dp[0][i]=(dp[0][i-1]>dp[1][i-1])?dp[0][i-1]:dp[1][i-1];
            dp[1][i]=dp[0][i-1]+nums[i-1];
        }
        int res=(dp[0][size]>dp[1][size])?dp[0][size]:dp[1][size];
        return res;
    }
    
};
//一个basic的常识是先将nums.size()替换成size，这样就只需要花一次调用.size()的时间