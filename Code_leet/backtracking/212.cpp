/**
 * 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words， 
 * 返回所有二维网格上的单词 。
 * 单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，
 * 其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
 * 同一个单元格内的字母在一个单词中不允许被重复使用。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int m = board.size();
        if (m == 0) return res;
        int n = board[0].size();
        unordered_set<string> wordset(words.begin(), words.end());
        int nums = words.size();
        for (int i=0; i<nums;i++ ){
            string word = words[i];
            for (int j=0; j<m; j++){
                for (int k=0; k<n; k++){
                    dfs(board ,word,j,k,0,res,wordset);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, string& word, int i, int j, int index, vector<string>& res, unordered_set<string>& wordset){
        if (index == word.size()){
            if (!wordset.count(word)) return;
            res.push_back(word);
            wordset.erase(word);
            return;
        }
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[index]){
            return;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        dfs(board,word,i+1,j,index+1,res,wordset);
        dfs(board,word,i-1,j,index+1,res,wordset);
        dfs(board,word,i,j+1,index+1,res,wordset);
        dfs(board,word,i,j-1,index+1,res,wordset);
        board[i][j] = temp;

    }

    
};