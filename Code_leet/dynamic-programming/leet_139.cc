/**
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
 * 如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
*/
#include <bits/stdc++.h>
#include <set>
using namespace std;
class Solution {
public:
    bool dp[301][301];
    set<string>  word;
    void fill(set <string> *setnow,vector<string>& wordDict) {
        while(!wordDict.empty()){
           (*setnow).insert(wordDict.back());
           wordDict.pop_back();
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set <string> set_temp;
        fill(&set_temp,wordDict);
        int size=s.size();
        for(int len=1;len<=size;len++){
            for(int i=0;i<size-len+1;i++){
                int j=i+len-1;
                std::string str_ij = s.substr(i,len);
                auto it = set_temp.find(str_ij);
                if(it != set_temp.end()){
                    dp[i][j]=true;
                    continue;
                }
                else{
                    for(int k=i;k<j;k++){
                        dp[i][j]=(dp[i][k]==true&&dp[k+1][j]==true);
                        if(dp[i][j]==true)break;
                    }
                }
            }
        }
        return dp[0][size-1];
    }
};