#include <stdio.h>
void jolly(void);
void deny(void);//以上为函数原型，说明要用这个东西
int main(void)
{
    jolly();
    jolly();
    jolly();
    deny();//函数调用，由题意三个jolly一个deny
return 0;
}
void jolly(void)//函数定义，他要干嘛
{
printf("For he's a jolly good fellow!\n");
}
void deny(void)
{
    printf("which nobody can fly\n");
}
//调用函数分三部，函数原型，函数调用（在main函数中调用它），函数定义（在函数里输入要做的事）
//要注意这里的函数原型中void表名函数没有返回值
//若第一个void 改为int ,int说明main（）的返回类型是整值，记得要加return 0
