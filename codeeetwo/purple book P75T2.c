//教训是if(test 1&& test 2)用&&才表示test1且test2 if(test 1 || test 2)表示逻辑或
//逗号操作符将两个或者多个表达式分隔开来，这些表达式自左向右逐个进行求值，整个逗号表达式的值就是最后那个表达式的值。
// 例如： if (b+1,c/2,d>0) 如果d的值大于0，那么整个表达式的值就为真。所以才会有216输出13：只判断了模七