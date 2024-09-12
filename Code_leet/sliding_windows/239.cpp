/**
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
 * 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
 * 返回 滑动窗口中的最大值 。
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
              while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);//i是一定要加的，只有后面的在该范围内表现得更好才要代替！！！
            
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        
        return res;
    }
};

/** 
 * 问题分析
set 的 erase 操作：

set 的 erase 操作是基于元素值的，而不是基于元素在数组中的位置。因此，s.erase(nums[i-k]) 可能会删除多个相同的元素，而不是仅仅删除滑动窗口中最早进入的那个元素。
set 的 rbegin() 方法：

set 的 rbegin() 方法返回的是 set 中最大的元素，但这并不一定是当前滑动窗口中的最大值。因为 set 中可能包含已经不在滑动窗口中的元素。
示例
考虑以下输入：

nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
CopyInsert
在某些情况下，set 中可能会包含已经不在滑动窗口中的元素，导致 rbegin() 返回的值不正确。

所以事实上可以用multiset改进：
#include <vector>
#include <set>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
            
            if (i >= k) {
                // 移除不在当前窗口的元素
                s.erase(s.find(nums[i - k]));
            }
            
            if (i >= k - 1) {
                // 获取当前窗口的最大值
                res.push_back(*s.rbegin());
            }
        }
        
        return res;
    }
};

但引入红黑树会慢很多，内存开支也更大。
 */