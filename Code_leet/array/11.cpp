/**
 * 给出一个非负整数数组 a1，a2，a3，…… an，每个整数标识一个竖立在坐标轴 x 位置的一堵高度为 ai 的墙，
 * 选择两堵墙，和 x 轴构成的容器可以容纳最多的水。
 */
# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int vlenght = height.size();
        int MaxWater=vlenght*min(height[0],height[vlenght-1]), maxstart=0, maxend= vlenght-1;
        int start=0, end=vlenght-1;
        while(start<end){
            int water=min(height[start],height[end])*(end-start);
            if(water>MaxWater){
                MaxWater=water;
                maxstart=start;
                maxend=end; 
            }
            if(height[start]<height[end]){
                start++;
            }else{
                end--;
                }

        }
    }
};

/*核心想法就是只有新的左&右大于对面才可能状态更新，否则不更新。 */