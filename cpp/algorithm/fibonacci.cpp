#include <iostream>
#include <chrono>

int fibonacciRecursion(int val)
{
    if (val == 0 || val == 1) 
    {
        return 1;
    }
    else
    {
        return fibonacciRecursion(val - 1) + fibonacciRecursion(val - 2);
    }
}

int valArray[10000];
int fibonacciDynamicProgrammingv1(int val)
{
    if (val == 0 || val == 1) 
    {
        return 1;
    }

    int result = 0;
    valArray[0] = 1, valArray[1] = 1;

    for (int i = 2; i <= val; ++i)
    {
        result = valArray[i-1] + valArray[i-2];
        valArray[i] = result;
    }
    return result;
}

int fibonacciDynamicProgrammingv2(int val)
{
    if (val == 0 || val == 1) 
    {
        return 1;
    }

    int lessOne = 1, lessTwo = 1, result = 0;

    for (int i = 2; i <= val; ++i)
    {
        result = lessOne + lessTwo;
        lessTwo = lessOne;
        lessOne = result;
    }
    return result;
}


int main()
{
    int val = 33;
    auto recursionST = std::chrono::high_resolution_clock::now();
    int resultRecursion = fibonacciRecursion(val);
    auto recursionET = std::chrono::high_resolution_clock::now();
    auto durationRecursion = std::chrono::duration_cast<std::chrono::microseconds>(recursionET - recursionST);
    std::cout << "fibonacci result of val is: " << resultRecursion << " used time is: " << durationRecursion.count() << " ms" << std::endl;

    auto DPv1ST = std::chrono::high_resolution_clock::now();
    int resultDPv1 = fibonacciDynamicProgrammingv1(val);
    auto DPv1ET = std::chrono::high_resolution_clock::now();
    auto durationDPv1 = std::chrono::duration_cast<std::chrono::microseconds>(DPv1ET - DPv1ST);
    std::cout << "fibonacci result of val is: " << resultDPv1 << " used time is: " << durationDPv1.count() << " ms" << std::endl;

    auto DPv2ST = std::chrono::high_resolution_clock::now();
    int resultDPv2 = fibonacciDynamicProgrammingv1(val);
    auto DPv2ET = std::chrono::high_resolution_clock::now();
    auto durationDPv2 = std::chrono::duration_cast<std::chrono::microseconds>(DPv2ET - DPv2ST);
    std::cout << "fibonacci result of val is: " << resultDPv2 << " used time is: " << durationDPv2.count() << " ms" << std::endl;
}