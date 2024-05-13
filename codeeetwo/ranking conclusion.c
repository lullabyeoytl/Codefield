/*
一   快速排序：，先找一随机数，在检索比他大放b，比他小放d，等于它的放c，放回后在对b,d递归，
int randint(int l, int r){ // 生成在 [l, r] 之间的随机数
	return rand() % (r - l + 1) + l;
}
void qsort(int l, int r){ // l 为左端点，r 为右端点
	if(l >= r){ // 如果长度为 0 就返回
		return;
	}
   // 给大家讲解一下为什么此时可以不用判长度为 1 的序列：
   // 因为序列中的这个数在添加的过程中会自动被分到 c 数组中去，而 c 在之后是不用排序的，相当于什么都没做，当然也可以在这里判一下长度为 1 的情况，直接 return 就可以了
	int num = randint(1, r), ind1 = 0, ind2 = 0, ind3 = 0; // 随机选择一个数，并定义三个作为下标的变量来记录长度、存放数据
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
再一次说明递归是先不要想太多细节，事实上只关注首位足矣*/
/*
二   sort cmp法
bool cmp(int a, int b){
	return a > b;
}
我们只需要定义两个与数组类型相同的变量作为参数，再返回两个数字的比较就可以了。

如果是从小到大排序，就用小于号连接两数；如果是从大到小排序，就用大于号连接两数，简记为：符号开口就代表大的在哪（大于号代表从大到小，小于号代表从小到大）。

写完这个函数，我们只需要在调用 sort 函数时在第三个参数写上函数名（例如 sort(a + l, a + r, cmp);）就可以了。

同样，结构体也可以用它排序。

例如我们定义一个结构体：

struct node{
	int x, y;
}c[1000];
此时，我们想这样对 c 排序：x 更大的在前，如果 x 相同则 y 更大的在前。
此时，我们可以这样写比较函数：
bool cmp(node a, node b){
	if(a.x != b.x){ // 如果两个 x 不等则以 x 的大小排序
		return a.x > b.x;
	}
	return a.y > b.y; // 否则以 y 的大小排序
注意：在结构体排序中，必须创建比较函数，否则会编译错误。
*/
/* 三 选择排序，每次选出第i小的（对iforj=i+1 到n,if A[i]>A[j]交换（swap)函数
   注意选择排序可以分块优化：
   分块即将序列分成几个部分，分别处理然后合并来得到最终答案。

分块的技巧极多，笔者不能全部解释明白，这里默认块长为 根号n（向下取整），详细说明写在后文的补充中，感兴趣的读者可以自行查看后面的内容。
由于块长已经设定为 
根号n ，序列将会被分成约根号n块（n 不一定为完全平方数），对这根号n个块分别进行选择排序。
现在序列是局部有序的，接下来该合并答案了，但是不知道如何合并。
局部有序。
只有一个选项，答案不言而喻：整个序列中最小的元素一定是其中一块的第一个元素。 每次遍历所有块的第一个元素，其中最小的元素即为当前序列最小的元素。
分块优化后的选择排序过程如下：
预处理：
将序列分成长度至多 根号n的根号n快
记录每个块的块首、块尾位置，对每个块进行选择排序。
合并块：
遍历所有块，找到当前序列最小的元素，记录其所属块的编号。
将当前最小的元素加入最终有序序列，这个元素所属块的块首前移。
如果某个块的块首超出了块尾，说明这个块是空的，跳过它即可。
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int n,block_len,block_num,head[1001],tail[1001],a[100001],ans[100001];
void selection_sort(int l,int r){
	int length=r-l+1;
	for(int i=1;i<=length;i++){
		int aim=l+i-1;
		for(int j=l+i-1;j<=r;j++) if(a[j]<a[aim]) aim=j;
		swap(a[l+i-1],a[aim]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];

	block_len=sqrt(n);//计算块长 
	block_num=(n-1)/block_len+1;//除法上取整计算块数,也可以换用下面一行统计块数 
//	for(int i=0;i<n;i+=block_len) block_num++;

	for(int i=1;i<block_num;i++){//最后一块(block_num)可能不完整,单独处理 
		head[i]=block_len*(i-1)+1;//块i包含的范围是[head[i],tail[i]] 
		tail[i]=head[i]+block_len-1;
	}
	head[block_num]=block_len*(block_num-1)+1;
	tail[block_num]=n;
    for(int i=1;i<=block_num;i++) selection_sort(head[i],tail[i]);

	for(int i=1;i<=n;i++){
		int aim=0;//aim:块首元素最小的块编号 
		for(int j=1;j<=block_num;j++)
			if(head[j]<=tail[j]){aim=j;break;}//找一个非空块的块首 
		
		for(int j=aim+1;j<=block_num;j++){
			if(head[j]>tail[j]) continue;
			if(a[head[j]]<a[head[aim]]) aim=j;
		}
		ans[i]=a[head[aim]];//计入答案 
		head[aim]++;//块首前移 
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}


*/
/*
    四冒泡，每次从第一个元素开始，相邻两数交换让大的放后面，一直到n+1-j个（后j个已然定序）
*/
/*
五 插入 即理牌

void insertion_sort(int arr[], int len) {
    for (int i = 1; i < len; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

*/
