/**求取表达式的值：luogu的题lol */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return dfs(s,i);
    }
    int dfs(string s,int & i){
        int n = s.size();
        int ans = 0;
        int sign = 1;
        while(i < n){
            if(s[i] == ' '){
                i++;
            }
            else if(s[i] == '+'){
                sign = 1;
                i++;
            }
            else if(s[i] == '-'){
                sign = -1;
                i++;
            }
            else if(isdigit(s[i])){
                int d = 0;
                while(i < n && isdigit(s[i])){
                    d = d * 10 + (s[i] - '0');
                    i++;
                }
                ans += sign * d;
            }
            else if(s[i] == '('){
                i++;
                ans += sign * dfs(s,i);
            }
            else if(s[i] == ')'){ 
                i++;
                return ans;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};


