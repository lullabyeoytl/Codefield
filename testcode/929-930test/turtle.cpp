#include <iostream>
using namespace std;

int main() {
    int redBalls, greenBalls, blueBalls;
    
    // 输入每个抽奖箱中的球的数量
    cin >> redBalls;
    cin >> greenBalls;
    cin >> blueBalls;
    
    // 计算不同的三球组合数
    int totalCombinations = redBalls * greenBalls * blueBalls;
    
    // 输出结果
    cout << totalCombinations << endl;
    
    return 0;
}
