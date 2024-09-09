#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10) return {};
        unordered_set<string> seen;
        unordered_set<string> repeated;
        for(int i=0; i<s.size()-9; i++){
            string sub = s.substr(i,10);
            if(seen.count(sub)){
                if(!repeated.count(sub)){
                repeated.insert(sub);
                }
            }
            else{
                seen.insert(sub);
            }
        }

        return vector<string>(repeated.begin(), repeated.end());
    }
};