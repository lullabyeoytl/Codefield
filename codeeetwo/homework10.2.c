#include <stdio.h>
main(){char*a="main(){char*a=%c%s%c;printf(a,34,a,34);}";printf(a,34,a,34);}
//注意到“的ascii码是34 34，a,,34就是在输出a,分别在输出里的%c,%s代换为
//双引号和a知输出语句就是这句话