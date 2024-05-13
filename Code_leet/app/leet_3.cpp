#include <bits/stdc++.h>
using namespace std;
class Solution {
    /**
     * 给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。
     * */
public:
    int lengthOfLongestSubstring(string s) {
        int vis[130]={0};
        int ans=0;
        int num_begin=0;
        vis[(int)s[0]]=0;
        if(s.size()==1)return 1;
        for(int i=1;i<s.size();i++){
            int temp= (int)s[i];
            if(vis[temp]<num_begin||(num_begin==0&&vis[temp]==0&&s[i]!=s[0])){
                vis[temp]=i;
                if(i==s.size()-1){
                    ans=max(i-num_begin+1,ans);
                }
            }
            else{
                ans=max(i-num_begin,ans);
                num_begin=vis[temp]+1;
                vis[temp]=i;
            }
        }
        return ans;
    }
};
/**废了，因为起点也是标记为零的情形卡了半天
 * 应该直接用bool vis,重复了就更新num_begin，在清空原num_begin与之前位置的数
 * 只是时间变2*n无太大影响
 * */