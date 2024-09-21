/**
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // 为了方便计算，在最后加一个 0
        stack<int> st;
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int w = i;
                if (!st.empty()) {
                    w = i - st.top() - 1;
                }
                res = max(res, h * w);
            }
            st.push(i);
        }
        return res;
    }
};