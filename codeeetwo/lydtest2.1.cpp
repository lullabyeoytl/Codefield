/*
 括号画家
 Candela是一名漫画家，她有一个奇特的爱好，就是在纸上画括号。这一天，刚刚起床的Candela画了一排括号序列，其中包含小括号()、中括号[]和大括号{}，总长度为N。这排随意绘制的括号序列显得杂乱无章，于是Candela定义了什么样的括号序列是美观的：
 (1)	空的括号序列是美观的；
 (2)	若括号序列A是美观的，则括号序列(A)、[A]、{A}也是美观的；
 (3)	若括号序列A、B都是美观的，则括号序列AB也是美观的；
 例如 [(){}]() 是美观的括号序列，而 )({)[}]( 则不是。
 现在Candela想在她绘制的括号序列中，找出其中连续的一段，满足这段子序列是美观的，并且长度尽量大。你能帮帮她吗？
 输入：
 第一行1个整数N，第二行1个长度为N的括号序列。
 各个测试点的N的大小：5,10,50,100,100,1000,1000,10000,10000,10000
 输出：
 一个整数，表示最长的美观的连续子序列的长度。

 cin 1:}[}({  cout1  0
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n;
char s[1010],b[1010];
int fh[300];
char tj[9]={'>','}',']',')','0','(','[','}','<'};
stack<int> st;
 
int main() {
    cin>>s;
    int l=strlen(s);
    fh['(']=-1;
    fh[')']=1;
    fh['[']=-2;
    fh[']']=2;
    fh['{']=-3;
    fh['}']=3;
    fh['<']=-4;
    fh['>']=4;
    
    for(int i=0; i<l; i++) {
        char c=s[i];
        if(fh[c]<0){
            st.push(i);
        }
        else{
            if(!st.empty()){
                int k=st.top(); 
                if(fh[s[k]]+fh[c]==0){
                    b[i]=b[k]=1;
                    st.pop();
                }
            }
        }
    }
    for(int i=0; i<l; i++){
        if(b[i]){
            cout<<s[i];
        }else{
            int k=fh[s[i]];
            if(k<0){
                cout<<s[i]<<tj[4+k];
            }else{
                cout<<tj[4+k]<<s[i];
            }
        }
    }
    return 0;
}