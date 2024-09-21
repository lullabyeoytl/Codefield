#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens){
            if(s == "+") {
                int b1=st.top();
                st.pop();
                int b2=st.top();
                st.pop();
                st.push(b1+b2);
            }
            else if(s == "-") {
                int b1=st.top();
                st.pop();
                int b2=st.top();
                st.pop();
                st.push(b2-b1);
            }
            else if(s == "*") {
                int b1=st.top();
                st.pop();
                int b2=st.top();
                st.pop();
                st.push(b1*b2);
            }
            else if(s == "/") {
                int b1=st.top();
                st.pop();
                int b2=st.top();
                st.pop();
                st.push(b2/b1);
            }
            else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};