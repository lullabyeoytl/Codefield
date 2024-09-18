/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='(' || c=='{' || c=='[') st.push(c);
            else if(c==')' && !st.empty() && st.top()=='(') st.pop();
            else if(c=='}' && !st.empty() && st.top()=='{') st.pop();
            else if(c==']' && !st.empty() && st.top()=='[') st.pop();
            else return false;
        }
        return st.empty();
    }
};
