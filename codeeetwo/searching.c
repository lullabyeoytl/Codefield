/*
回溯法：例题洛谷1706
按照字典序输出自然数 
1
1 到 n 所有不重复的排列，即 n 的全排列，要求所产生的任一数字序列中不允许出现重复的数字。
代码
#include <iomanip>
#include <iostream>
using namespace std;
int n;
bool vis[50];  // 访问标记数组，0表示未用过，1表示用过
int a[50];     // 排列数组，按顺序储存当前搜索结果

void dfs(int step) {
  if (step == n + 1) {  // 边界
    for (int i = 1; i <= n; i++) {
      cout << setw(5) << a[i];  // 保留5个场宽
    }
    cout << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {  // 判断数字i是否在正在进行的全排列中
      vis[i] = 1;
      a[step] = i;
      dfs(step + 1);//递归，但有可能递归不下去，就跳出
      vis[i] = 0;  // 这步相当于跳出后“回溯”，这个step不用i，继续循环看i+1,此时要归0表示这一步不使用该数i, 置0后允许下一步使用
    }
  }
  return;
}

int main() {
  cin >> n;
  dfs(1);
  return 0;
}




*/