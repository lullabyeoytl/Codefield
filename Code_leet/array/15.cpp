/**
 * 给你一个整数数组 nums ，
 * 判断是否存在三元组 [nums[i], nums[j], nums[k]] 
 * 满足 i != j、i != k 且 j != k ，
 * 同时还满足 nums[i] + nums[j] + nums[k] == 0 。
 * 请你返回所有和为 0 且不重复的三元组。
 */ 
# include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        map <int,int> times;
        for (int i = 0; i < n - 2; i++) {
            if (times.count(nums[i]) > 0) {
                continue;
            }
            times[nums[i]] = 1;
            map <int,int> jtimes;
            int ijend = n - 1;
            for (int j = i + 1; j < ijend; j++) {
                if (jtimes.count(nums[j]) > 0) {
                    continue;
                }
                jtimes[nums[j]] = 1;
                int target = -nums[i] - nums[j];
                while(ijend > j && nums[ijend]>target){
                    ijend--;
                }
                if(nums[ijend]==target&&ijend!=j){
                    res.push_back({nums[i],nums[j],nums[ijend]});
                    
                }
            }
        }
        return res;
    
    }
};

/**一开始的想法是先排序，然后固定一个数，再用find来找target,但是这样会超时，
 * 所以改成了双指针法，先固定一个数，然后用双指针法找另两个数，这样时间复杂度是O(n^2) 
 * 这是困难点其一
 * 其二是要排除重复，这个就只需要用个map来标记就好
 * 另外边界一定要想清，例如ijend可能回到什么指一定要想清楚，否则会出错*/