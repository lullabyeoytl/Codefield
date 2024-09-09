/**
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
 * 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 */
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), tot = 0;
        vector<int> c1(60), c2(60);
        for (char x : t) {
            if (++c1[getIdx(x)] == 1) tot++;
        }
        string ans = "";
        for (int i = 0, j = 0; i < n; i++) {
            int idx1 = getIdx(s[i]);
            if (++c2[idx1] == c1[idx1]) tot--;
            while (j < i) {
                int idx2 = getIdx(s[j]);
                if (c2[idx2] > c1[idx2] && --c2[idx2] >= 0) j++;
                else break;
            }
            if (tot == 0 && (ans.empty() || ans.length() > i - j + 1)) ans = s.substr(j, i - j + 1);
        }
        return ans;
    }
    int getIdx(char x) {
        return x >= 'A' && x <= 'Z' ? x - 'A' + 26 : x - 'a';
    }
};

