/**
 * 编写一个程序，通过填充空格来解决数独问题。
 * 数独的解法需 遵循如下规则：
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 * 数独部分空格内已填入了数字，空白格用 '.' 表示
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool Panduan(int hang,int lie,char zhi,vector<vector<char>>& board){
        for(int i = 0;i < board[hang].size();i++){
            if(board[hang][i]==zhi)return false;
        }
        for(int j = 0;j < board.size();j++){
            if(board[j][lie]==zhi)return false;
        }
        int hangstart = (hang/3)*3;
        int liestart = (lie/3)*3;
        for(int i = hangstart;i < hangstart+3;i++){
            for(int j = liestart;j < liestart+3;j++){
                if(board[i][j]==zhi)return false;
            }
        }
        return true;
    }

    bool Huisu(vector<vector<char>>& board){
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[i].size();j++){
                if(board[i][j] != '.')continue;
                for(char k = '1';k <= '9';k++){
                    if(Panduan(i,j,k,board)){
                        board[i][j] = k;
                        if(Huisu(board)==true)return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        Huisu(board);
    }
};
