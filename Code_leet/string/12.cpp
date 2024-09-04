/**
七个不同的符号代表罗马数字，其值如下：
符号	值
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
罗马数字是通过添加从最高到最低的小数位值的转换而形成的。
将小数位值转换为罗马数字有以下规则：
如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，
将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。
如果该值以 4 或 9 开头，使用 减法形式，表示从以下符号中减去一个符号，
例如 4 是 5 (V) 减 1 (I): IV ，9 是 10 (X) 减 1 (I)：IX。
仅使用以下减法形式：4 (IV)，9 (IX)，40 (XL)，90 (XC)，400 (CD) 和 900 (CM)。
只有 10 的次方（I, X, C, M）最多可以连续附加 3 次以代表 10 的倍数。
你不能多次附加 5 (V)，50 (L) 或 500 (D)。如果需要将符号附加4次，请使用 减法形式。
给定一个整数，将其转换为罗马数字。
 */
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        while (num>=1000){
            roman += "M";
            num -= 1000;
        }

        if (num>=900){
            num -= 900;
            roman += "CM";
        }
        
        else if(num>=500){
            num-=500;
            roman += "D";
            while (num>=100){
                roman += "C";
                num-=100;
            }
        }

        else if(num>= 400){
            num-=400;
            roman += "CD";
        }

        else{
            while(num>=100){
                roman += "C";
                num-=100;
            }
        }
        if (num>=90){
                num-=90;
                roman += "XC";
            }
            else if (num>=50){
                num-=50;
                roman += "L";
                while (num>=10){
                    roman += "X";
                    num-=10;
                }
            }

            else if (num>=40){
                num-=40;
                roman += "XL";
            }

            else{
                while (num>=10){
                    roman += "X";
                    num-=10;
                }
            }
            if (num>=9){
                num-=9;
                roman += "IX";
            }
            else if (num>=5){
                num-=5;
                roman += "V";
                while (num>=1){
                    roman += "I";
                    num-=1;
                }
            }
            else if (num>=4){
                num-=4;
                roman += "IV";
            }
            else{
                while (num>=1){
                    roman += "I";
                    num-=1;
                }
            }
        return roman;
    }
};