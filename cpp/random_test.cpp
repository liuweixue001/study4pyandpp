#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random> 
#include <iostream>

int main() {
    
    /*使用当前时间作为种子
    time 函数是 C 标准库 <time.h> 中提供的一个函数，
    用于获取当前的系统时间。在你的代码中，time(NULL) 返回的是
    自 1970 年 1 月 1 日 00:00:00 UTC（通常被称为 Epoch 时间）以来的秒数。*/

    srand((unsigned int)time(NULL)); 

    // 生成并输出 5 个随机数
    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", rand());
    }
    printf("\n\n");

    // 使用Mersenne Twister算法作为随机数引擎  
    std::mt19937 rng(std::random_device{}());  

    // 使用uniform_int_distribution来生成指定范围的随机数  
    std::uniform_int_distribution<int> dist(0, 9999999); // 生成0到99之间的随机数  

    // 生成并输出5个随机数  
    for (int i = 0; i < 5; ++i) 
    {  
        int random_value = dist(rng);  
        printf("%d ", random_value);
    }  
    printf("\n");

    return 0;
}
