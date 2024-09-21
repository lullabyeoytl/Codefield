/**
 * 给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 
 * （以 '/' 开头），请你将其转化为 更加简洁的规范路径。
 * 在 Unix 风格的文件系统中规则如下：
 * 一个点 '.' 表示当前目录本身。
 * 此外，两个点 '..' 表示将目录切换到上一级（指向父目录）。
 * 任意多个连续的斜杠（即，'//' 或 '///'）都被视为单个斜杠 '/'。
 * 任何其他格式的点（例如，'...' 或 '....'）均被视为有效的文件/目录名称。
 * 返回的 简化路径 必须遵循下述格式：
 * 始终以斜杠 '/' 开头。
 * 两个目录名之间必须只有一个斜杠 '/' 。
 * 最后一个目录名（如果存在）不能 以 '/' 结尾。
 * 此外，路径仅包含从根目录到目标文件或目录的路径上的目录
 * （即，不含 '.' 或 '..'）。返回简化后得到的 规范路径 。
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> st; // 使用双端队列作为栈来存储目录
        int n = path.length();
        
        for (int i = 0; i < n; i++) {
            // 跳过连续的斜杠
            if (path[i] == '/') {
                while (i < n && path[i] == '/') {
                    i++;
                }
                if (i == n) break; // 遇到路径结尾，退出
                // 处理当前有效目录名
                int start = i; // 记录目录名的开始位置
                while (i < n && path[i] != '/') {
                    i++;
                }
                string dir = path.substr(start, i - start);
                if (dir == "..") {
                    // 如果是 ..，则弹出上级目录
                    if (!st.empty() && st.back() != "..") {
                        st.pop_back();
                    }
                } else if (dir != "." && dir != "") {
                    // 如果是有效目录名，压入栈
                    st.push_back(dir);
                }
                i--; // 因为外层循环会自增，所以需要减一
            }
        }
        
        // 构建最终的简化路径
        string res = "";
        if (st.empty()) return "/"; // 如果栈为空，返回根目录
        
        while (!st.empty()) {
            res = "/" + st.back() + res; // 从栈中弹出目录并添加到结果字符串中
            st.pop_back();
        }
        
        return res; 
    }
};