/**
 * 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：
 * 每一对相邻的单词只差一个字母。
 * 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
 * sk == endWord
 * 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。

 
示例 1：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：5
解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
示例 2：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
输出：0
解释：endWord "cog" 不在字典中，所以无法进行转换。
 

提示：

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord、endWord 和 wordList[i] 由小写英文字母组成
beginWord != endWord
wordList 中的所有字符串 互不相同
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string s, e;
    unordered_set<string> wordSet;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        s = beginWord; e = endWord;
        for (string w : wordList) wordSet.insert(w);
        if (wordSet.find(e) == wordSet.end()) return 0;
        int ans = bfs();
        return ans == -1 ? 0 : ans + 1;
    }
private:
    int bfs() {
        deque<string> dq1, dq2;
        unordered_map<string, int> m1, m2;
        dq1.push_back(s);
        m1[s] = 0;
        dq2.push_back(e);
        m2[e] = 0;
        while (!dq1.empty() && !dq2.empty()) {
            int t = -1;
            if (dq1.size() <= dq2.size()) t = update(dq1, m1, m2);
            else t = update(dq2, m2, m1);
            if (t != -1) return t;
        }
        return -1;
    }
    int update(deque<string>& dq, unordered_map<string, int>& cur, unordered_map<string, int>& other) {
        int m = dq.size();
        while (m-- > 0) {
            string poll = dq.front();
            dq.pop_front();
            int n = poll.length();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 26; j++) {
                    string sub = poll.substr(0, i) + static_cast<char>('a' + j) + poll.substr(i + 1);
                    if (wordSet.find(sub) != wordSet.end()) {
                        if (cur.find(sub) != cur.end() && cur[sub] <= cur[poll] + 1) continue;
                        if (other.find(sub) != other.end()) {
                            return cur[poll] + 1 + other[sub];
                        } else {
                            dq.push_back(sub);
                            cur[sub] = cur[poll] + 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
/**
 * 本来以为是简单的建立图后A*算法，然后发现根本建立不了图
 * bfs+每个单词暴力的去查肯定是可以的，但是怎么样更快：考虑双端bfs(想了一下a*确实没用：a*某种程度上要“比较公平”的条件下预估，而wordlist中完全可能有恶心的数卡着)
*/
