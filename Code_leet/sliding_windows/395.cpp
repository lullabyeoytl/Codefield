/**
 * 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串，
 *  要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
 * 如果不存在这样的子字符串，则返回 0。
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if (n == 0 || k > n) return 0;

        // 统计字符频率
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }

        // 查找不满足条件的字符
        for (auto &it : charCount) {
            if (it.second < k) {
                int maxLength = 0;
                string segment;

                // 用不满足条件的字符分割字符串
                for (char c : s) {
                    if (c == it.first) {
                        // 如果遇到不满足条件的字符，处理当前子串
                        maxLength = max(maxLength, longestSubstring(segment, k));
                        segment.clear(); // 清空当前子串
                    } else {
                        // 记录连续的满足条件的字符
                        segment += c;
                    }
                }
                // 处理最后一个子串
                maxLength = max(maxLength, longestSubstring(segment, k));
                return maxLength; // 返回最大值
            }
        }
        return n; // 所有字符都满足条件
    }
};

/**
 * 频率统计：首先统计每个字符的出现次数。
 * 
 * 寻找不满足条件的字符：如果某个字符的出现次数小于 k，则将字符串按该字符分割。
 * 
 * 处理分段字符串：在遍历原字符串时，如果遇到不满足条件的字符，记录当前的子串（连续字符）并递归处理它；
 * 
 * 同时，如果遍历结束时还有剩余的子串，也要处理。
 * 
 * 返回最大长度：在完成处理后，返回满足条件的最长连续子串的长度。
 * 
 * ai比我厉害多了。。。
 */