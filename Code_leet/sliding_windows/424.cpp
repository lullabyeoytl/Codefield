/**
 * 给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，并将其更改为任何其他大写英文字符。
 * 该操作最多可执行 k 次。
 * 在执行上述操作后，返回 包含相同字母的最长子字符串的长度。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count(string s, int k, char ch) {
        int n = s.size();
        int res = 0;
        for(int l = 0, r = 0, sum = 0; r < n; ++r) {
            sum += (s[r] != ch ? 1 : 0);
            while(sum > k) {
                sum -= (s[l++] != ch ? 1 : 0);
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
    int characterReplacement(string s, int k) {
        int res = 0;
        for(int i = 0; i < 26; ++i) {
            res = max(res, count(s, k, 'A' + i));
        }
        return res;        
    }
};
//这题边界条件特别犯人，一定要想好！！！，例如k=0,结尾怎么解，最后没有替换等等！