#include <stdio.h>
#include<stdlib.h>
int a[100005] ; int b[100005]; int c[100005]; int d[100005];
int randint(int l, int r){ // 生成在 [l, r] 之间的随机数
	return rand() % (r - l + 1) + l;
}
void qsort(int l, int r){ // l 为左端点，r 为右端点
	if(l >= r){ // 如果长度为 0 就返回
		return;
	}
   // 给大家讲解一下为什么此时可以不用判长度为 1 的序列：
   // 因为序列中的这个数在添加的过程中会自动被分到 c 数组中去，而 c 在之后是不用排序的，相当于什么都没做，当然也可以在这里判一下长度为 1 的情况，直接 return 就可以了
	int num = randint(l, r), ind1 = 0, ind2 = 0, ind3 = 0; // 随机选择一个数，并定义三个作为下标的变量来记录长度、存放数据
	for(int i = l;i <= r;i++){ // 将 a 中的数分别分到 b, c, d（如上所述）
		if(a[i] < a[num]){
			b[ind1++] = a[i];
		}
		else if(a[i] == a[num]){
			c[ind2++] = a[i];
		}
		else{
			d[ind3++] = a[i];
		}
	}
	for(int i = 0;i < ind1;i++){ // 将 b, c, d 中的数重新放回 a
		a[i + l] = b[i];
	}
	for(int i = 0;i < ind2;i++){
		a[i + ind1 + l] = c[i];
	}
	for(int i = 0;i < ind3;i++){
		a[i + ind1 + ind2 + l] = d[i];
	}
	qsort(l, l + ind1 - 1); // 继续排序原来的 b 和 d 递归
	qsort(l + ind1 + ind2, r);
}
 int main (void)
 {
    int N;
    scanf("%d" , &N);
    for(int i = 1; i<= N ; i++ )
    scanf("%d" , &a[i]);
    qsort(1, N);
    for( int i= 1; i<=N ; i++)
    {
        printf("%d" , a[i]);
        printf(" ");
    }
    return 0 ; 

 }