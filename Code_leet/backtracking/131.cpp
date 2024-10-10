/*给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 
回文串
 。返回 s 所有可能的分割方案。*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(s, 0, path, res);
        return res;
    }

    void backtrack(string s, int start, vector<string>& path, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};