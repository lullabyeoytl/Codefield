#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(int left, int right, int n, string s, vector<string>& res){
        if(left == n && right == n){
            res.push_back(s);
            return;
        }
        if(left<n){

            dfs(left+1, right, n, s+"(", res);
        }
        if(right<left){
            dfs(left, right+1, n, s+")", res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, n, "", res);
        return res;

    }
};