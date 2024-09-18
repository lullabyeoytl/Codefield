/*给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
计算按此排列的柱子，下雨之后能接多少雨水。
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
{
    int ans = 0;
    stack<int> st;
    for (int i = 0; i < height.size(); i++)
    {
        while (!st.empty() && height[st.top()] < height[i])
        {
            int cur = st.top();
            st.pop();
            if (st.empty()) break;
            int l = st.top();
            int r = i;
            int h = min(height[r], height[l]) - height[cur];
            ans += (r - l - 1) * h;
        }
        st.push(i);
    }
    return ans;
}

};
