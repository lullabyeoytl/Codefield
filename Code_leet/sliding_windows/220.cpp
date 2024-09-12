/**
 * 给你一个整数数组 nums 和两个整数 indexDiff 和 valueDiff 。
 * 找出满足下述条件的下标对 (i, j)：
 * i != j,
 * abs(i - j) <= indexDiff
 * abs(nums[i] - nums[j]) <= valueDiff
 * 如果存在，返回 true ；否则，返回 false 
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set <long> st;
        for (int i =0; i < nums.size(); i++){
            auto it = st.lower_bound((long)nums[i] - valueDiff);
            if (it!= st.end() && *it <= (long)nums[i] + valueDiff) return true;
            st.insert((long)nums[i]);
            if (i >= indexDiff) st.erase((long)nums[i-indexDiff]);
        }    
        return false;
    }
};

/**要对c++ set熟悉！ set维护了一个有序的集合！（红黑树） */