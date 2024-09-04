/**
 * 将一个给定字符串 s 根据给定的行数 numRows ，
 * 以从上往下、从左到右进行 Z 字形排列。
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串
 */
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res = "";
        int len = s.length();
        int cycle = 2 * numRows - 2;
        for(int i=0; i<numRows;i++){
            for(int j=i;j<len;j+=cycle){
                res += s[j];
                if(i!=0 && i!=numRows-1 && j+cycle-2*i<len){
                    res += s[j+cycle-2*i];
                }
            }
        }
        return res;
    }
};