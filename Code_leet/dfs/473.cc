#include <bits/stdc++.h>
using namespace std;
/**
 * 这是 LeetCode 上的 473. 火柴拼正方形 ，难度为 中等。
 * 你将得到一个整数数组 matchsticks，其中 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。
 * 你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。
 * 如果你能使这个正方形，则返回 true，否则返回 false。
*/
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0) {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());// 减少搜索量
        vector <int> edges;
        edges.reserve(4);
        return dfs(0,totalLen/4,edges,matchsticks);
    }
private:
    bool cmp(int a,int b){
        return a>b;
    }
    bool dfs(int index,int len,vector<int> &edge,vector <int> &matchsticks){
        if (index == matchsticks.size()-1) {
            return true;
        }
        for(int i=0;i<edge.size();i++){
            if(edge[i]==len)continue;
            else{
                edge[i]+=matchsticks[index];
                if(edge[i]<=len&&dfs(index + 1, len, edge,matchsticks ))
                return true;
                else edge[i]-=matchsticks[index];
            }
        }
        return false;
    }
};