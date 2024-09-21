/**
 * 给你一个字符串化学式 formula ，返回 每种原子的数量 。
 * 原子总是以一个大写字母开始，接着跟随 0 个或任意个小写字母，表示原子的名字。
 * 如果数量大于 1，原子后会跟着数字表示原子的数量。如果数量等于 1 则不会跟数字。
 * 例如，"H2O" 和 "H2O2" 是可行的，但 "H1O2" 这个表达是不可行的。
 * 两个化学式连在一起可以构成新的化学式。
 * 例如 "H2O2He3Mg4" 也是化学式。
 * 由括号括起的化学式并佐以数字（可选择性添加）也是化学式。
 * 例如 "(H2O2)" 和 "(H2O2)3" 是化学式。
 * 返回所有原子的数量，格式为：第一个（按字典序）原子的名字，跟着它的数量（如果数量大于 1），然后是第二个原子的名字（按字典序），跟着它的数量（如果数量大于 1），以此类推。
 */
#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int get_num(string s) {
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            else {
                break;
            }
        }
        if (num == 0) {
            return 1;
        }
        return num;
    }
    
    string get_atom(string s) {
        if (s[1]>='a'&&s[1]<='z'){
            string s1 = std::string (1,s[0]);
            string s2 = std::string (1,s[1]);
            s1+=s2;
            return s1;
        }
        else{
            string s1 = std::string (1,s[0]);
            return s1;
        }
    }
    string countOfAtoms(string formula) {
        stack<pair<string, int>> st;
        int n = formula.size();
        int i = 0;
        map<string, int> mp;
        while (i < n) {
            if (formula[i]>='0'&&formula[i]<='9'){
                continue;
            }
            else if(formula[i] =='('){
                st.push(make_pair("(",1));
                i++;
            }
            else if(formula[i] >= 'A' && formula[i] <= 'Z'&& !st.empty()){
                string s = get_atom(formula.substr(i,2));
                s.size()==1?st.push(make_pair(s,get_num(formula.substr(i+1,n-i-1)))):st.push(make_pair(s,get_num(formula.substr(i+2,n-i-2))));
                i+=s.size();
            }
            else if(formula[i] >= 'A' && formula[i] <= 'Z'&& st.empty()){
                string s = get_atom(formula.substr(i,2));
                int num = s.size()==1?get_num(formula.substr(i+1,n-i-1)):get_num(formula.substr(i+2,n-i-2));
                mp[s]+=num;
                i+=s.size();
            }
            else if(formula[i] == ')'){
                stack <pair<string, int>> temp;
                int num = i==n-1?1:get_num(formula.substr(i+1,n-i-1));
                while(st.top().first != "("){
                    string s = st.top().first;
                    int count = st.top().second;
                    count*=num;
                    st.pop();
                    temp.push(make_pair(s,count));
                }
                st.pop();
                if(!st.empty()){
                     while(!temp.empty()){
                        pair<string, int> p = temp.top();
                        temp.pop();
                        st.push(p);
                     }
                }
                if(st.empty()){
                    while(!temp.empty()){
                        mp[temp.top().first]+=temp.top().second;
                        temp.pop();
                    }
                }
                i++;
            }
            else{
                i++;
            }
            
        }
        string res = "";
        for(auto it = mp.begin(); it!= mp.end(); it++){
            if(it->second>1){
                res+=it->first+to_string(it->second);
            }
            else{
                res+=it->first;
            }
        }
        return res;
    }
};
/**
 * if (formula[i]>='A' && formula[i]<='Z') {
                if(i+1<n && (formula[i+1]>='a' && formula[i+1]<='z')){
                    string s1 = std::string (1,formula[i]);
                    string s2 = std::string (1,formula[i+1]);
                    s1+=s2;
                    
                    i+=2;
                }
            }   
 */