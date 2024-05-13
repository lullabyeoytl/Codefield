用于存放各个功能模块的头文件
头文件(.h)
头文件用来写 类的声明 （包括类的成员的声明和方法声明）、函数原型、#define 常数等，但是很少会写出具体的实现和细节。就好比抽象类一样。

头文件很有意思的是，开头和结尾必须按照以下格式：

#ifndef MYCLASS_H
#define MYCLASS_H

// code here

#endif
当时我看到这个是极其的不理解和迷茫的，后来阅读了别人的博文才略懂。

首先解释他是干嘛使的，这是防止头文件被重复引用。什么叫被重复引用？就是同一个头文件(.h)在同一个源文件(.cpp)中被include了多次。这种错误常常是因为include嵌套。举个最简单的例子，存在cellphone.h这个头文件引用了#include "huawei.h"，之后又有china.cpp这个源文件同时导入了#include "cellphone.h" 和 #include "huawei.h"。此时huawei.h就在一个源文件里引用了两次。

那么，某些时候，只是因为include了两遍，增大了编译器的工作量。如果是小型程序的话还好说，但是大型工程甚至会增长几个小时的编译时间。但是另一些情况，会引起很严重的错误。比如在头文件中定义了全局变量会引起重复定义。

所以就有了我们上面那些看起来乱七八糟的代码，下面开始解释。

#ifndef MYCLASS_H 的意思是 if not define myclass.h，这样看就很好理解了，如果引用这个头文件的源文件不存在myclass.h这个头文件，那么接下行 #define MYCALSS_H， 引入myclass.h。然后就是我们头文件的代码。如果已经有了，直接跳到 #endif。

理论上来说，上面这个片段的MYCLASS_H是可以任意命名的，但是约定俗成的，为了可读性的，我们都把它命名为这个头文件的大写和下划线的形式。如下面这一段代码：

#ifndef HUAWEI_H       // 防止huawei.h被重复引用
#define HUAWEI_H

#include <cmath>       // 引用标准库
#include "honor.h"     // 引用非标准库头文件
...
void Function();  	   // 全局函数声明
class Mate20{		   // 类声明
    public: Mate20();  // 构造函数声明
 			~Mate20(); // 析构函数声明  
    private:
    protected:
};

#endif
上面的代码其实已经很好的解释了头文件的作用——声明。可以看见内部的函数和方法仅仅是声明，而都没有写入具体细节。