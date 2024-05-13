#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> d;
        d.push(root);
        while (!d.empty()) {
            int sz = d.size();
            while (sz-- > 0) {
                TreeNode* node = d.front();
                d.pop();
                if (node->left) d.push(node->left);
                if (node->right) d.push(node->right);
                if (sz == 0) ans.push_back(node->val);
            }
        }
        return ans;
    }
};