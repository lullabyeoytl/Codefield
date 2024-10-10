/**
 * 按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，
 * 一个表示此过程的 转换序列 是形式上像 beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，并满足：
 * 每对相邻的单词之间仅有单个字母不同。
 * 转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。
 * 注意，beginWord 不必是字典 wordList 中的单词。
 * sk == endWord
 * 给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。
 * 请你找出并返回所有从 beginWord 到 endWord 的 最短转换序列 ，
 * 如果不存在这样的转换序列，返回一个空列表。
 * 每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
private:
    list<string> path;
    unordered_set<string> dict;
    vector<vector<string>> ret;
    unordered_set<string> curLevel;
    unordered_set<string> nextLevel;
    unordered_map<string, vector<string>> g;

    // begin -> end，一层层 bfs 去建图
    // 找到 begin 到 end 的路径，则返回 true
    bool bfs(string& begin, string& end)
    {
        bool flag = false;
        curLevel.emplace(begin);
        while(!curLevel.empty())
        {
            for(auto& s : curLevel) dict.erase(s);
            for(auto& s : curLevel)
            {
                string tmp = s;
                // 每个位置，字符 a-z 都试一遍
                for(int i = 0; i < tmp.size(); ++i)
                {
                    char old = tmp[i];
                    for(char ch = 'a'; ch <= 'z'; ++ch)
                    {
                        if(ch != old)
                        {
                            tmp[i] = ch;
                            if(dict.count(tmp))
                            {
                                if(tmp == end) flag = true; // 找到 begin 到 end 的路径了
                                g[tmp].emplace_back(s); // 建反图
                                if(!nextLevel.count(tmp)) nextLevel.emplace(tmp);
                            }
                        }
                    }
                    tmp[i] = old;
                }
            }

            // 找到了路径
            if(flag) return true;
            else
            {
                curLevel.swap(nextLevel);
                nextLevel.clear();
            }
        }
        return false;
    }

    // dfs 利用 bfs 形成的反图去生成路径
    void dfs(string& word, string& target)
    {
        path.emplace_front(word);
        if(word == target)
        {
            ret.emplace_back(vector<string>(path.begin(), path.end()));
        }

        for(auto& next : g[word])
        {
            dfs(next, target);
        }
        // 回溯
        path.pop_front();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        dict = unordered_set<string>(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return {};

        if(bfs(beginWord, endWord)) dfs(endWord, beginWord);
        return ret;
    }
};

