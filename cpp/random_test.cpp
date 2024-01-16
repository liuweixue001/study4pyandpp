#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    /*使用当前时间作为种子
    time 函数是 C 标准库 <time.h> 中提供的一个函数，
    用于获取当前的系统时间。在你的代码中，time(NULL) 返回的是
    自 1970 年 1 月 1 日 00:00:00 UTC（通常被称为 Epoch 时间）以来的秒数。*/

    srand((unsigned int)time(NULL)); 

    // 生成并输出 5 个随机数
    for (int i = 0; i < 5; i++) {
        printf("%d\n", rand());
    }

    return 0;
}
