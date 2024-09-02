/**
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串的长度。
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n < 2) return n;
        map<char, int> mp;
        int i = 0, j = 0, ans = 0;
        while (j < n) {
            if(mp.count(s[j]) == 0){
                mp[s[j]] = j;
                ans = max(ans, j - i+1);
                j++;
            }else{

                i = max(i, mp[s[j]] + 1);
                mp[s[j]] = j;
                ans = max(ans, j - i+1);
                j++;
            }
        }
        return ans;
    }
};