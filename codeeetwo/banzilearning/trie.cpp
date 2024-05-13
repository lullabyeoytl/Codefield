/* 
初始化根节点1，按多叉树形式与字典序方式排，各节点编号按出现顺序排列
int trie[size][26]:trie[i][j]指编号为i的（自然总数有size个）j子节点的编号
int tot = 1;//tot为目前节点数，初始化为一
//插入：
void insert(char*str)//插入str
{
    int len = strlen(str),p=1//p指下一步要操作的编号，初始化为1
    for(int k=0;k<=len-1;k++)
    {
        int ch = str[k]-'a';
        if(trie[p][ch]==0)//如果编号为p的节点无ch这一儿子
        {
            trie[p][ch]=++tot//tot节点数加一，新节点第++tot个出现编号为此
        }
        p=trie[p][ch];//以这个儿子的编号更新编号，继续操作
    }
    end[p] = true;//表示该节点结尾是个单词
}
//查询操作；
bool search(char*str)
{
    int len = strlen(str)-1;p=1//p=1只从根节点开始查
    for(int k =0;k<len;k++)
    {
        p=trie[p][str[k]-'a'];//更新节点
        if(p==0) return false//等于零说明没编号
    }
    return end[p] ; //到了最后一个，end[p]是true表示为一个单词
}

*/
 