/*
1.设 J{n,k} 表示规模分别为 n,k 的约瑟夫问题的答案。我们有如下递归式
j{n,k} = （j{n-1,k} +k) mod n;
int josephus(int n, int k) {
  int res = 0;
  for (int i = 1; i <= n; ++i) res = (res + k) % i;
  return res;
}


*/