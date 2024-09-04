/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(string digits, string mapping[], int index, string path, vector<string>& result){
    if (index == digits.size()){
        result.push_back(path);
        return;
    }
    
    int digit = digits[index] - '0';
    string letters = mapping[digit];
    for (int i = 0; i < letters.size(); i++){
        path.push_back(letters[i]);
        dfs(digits, mapping, index + 1, path, result);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) return result;
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    dfs(digits, mapping, 0, "", result);
    return result;

}