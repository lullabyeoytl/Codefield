/**
 * 现有一个有向图，其中包含 n 个节点，节点编号从 0 到 n - 1。此外，该图还包含了 n 条有向边
 * 给你一个下标从 0 开始的数组 edges，其中 edges[i] 表示存在一条从节点 i 到节点 edges[i] 的边
 * 想象在图上发生以下过程：
 * 你从节点 x 开始，通过边访问其他节点，直到你在 此过程 中再次访问到之前已经访问过的节点。
 * 返回数组 answer 作为答案，其中 answer[i] 表示如果从节点 i 开始执行该过程，你可以访问到的不同节点数。
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int he[200010], e[200010], ne[200010], idx;
    void add(int a, int b) {
        e[idx] = b;
        ne[idx] = he[a];
        he[a] = idx++;
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> in(n, 0), ans(n, 0);
        for (int x : edges) in[x]++;
        queue<int> d;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) d.push(i);
        }
        while (!d.empty()) {
            int t = edges[d.front()];
            d.pop();
            if (--in[t] == 0) d.push(t);
        }
        set<int> s;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) continue;
            vector<int> list;
            list.push_back(i);
            int j = edges[i], val = 1;
            while (j != i) {
                list.push_back(j);
                j = edges[j];
                val++;
            }
            for (int x : list) {
                s.insert(x);
                in[x] = 0;
                ans[x] = val;
            }
        }
        memset(he, -1, sizeof(he));
        for (int i = 0; i < n; i++) add(edges[i], i);
        for (int u : s) {
            int val = ans[u];
            queue<int> de;
            de.push(u);
            while (!de.empty()) {
                int sz = de.size();
                while (sz-- > 0) {
                    int t = de.front();
                    de.pop();
                    ans[t] = val;
                    for (int i = he[t]; i != -1; i = ne[i]) {
                        int j = e[i];
                        if (ans[j] != 0) continue;
                        de.push(j);
                    }
                }
                val++;
            }
        }
        return ans;
    }
};
/*先深度搜在倒回，明显可以用双端队列*/