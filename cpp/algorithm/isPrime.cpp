#include <iostream>
#include <cmath>

bool isPrime(int num)
{
    if (num == 1)  // 1不是质数
    {
        return false;
    }
    if (num == 2)  // 2是质数
    {
        return true;
    }
    if (num % 2 == 0) // 大于2的偶数不是质数
    {
        return false;
    }
    int sqrtNum = static_cast<int>(std::sqrt(num)); // 取小于根号的范围
    for (int i = 3; i < sqrtNum; i += 2) // 去除偶数
    {
        if (num % i == 0)
        {
            return false;
        } 
    }
    return true;
}

int main()
{
    int testNum = 33;
    if (isPrime(testNum))
    {
        std::cout << "testNum: " << testNum << " is a Prime" << std::endl;
    }
    else
    {
        std::cout << "testNum: " << testNum << " is not a Prime" << std::endl;
    }
    return 0;
}