#include <iostream>
#include <vector>

/*
有N个正整数组成的一个序列。给定整数sum，求长度最长的连续子序列，使它们的和等于sum，返回此子序列的长度，如果没有满足
要求的序列，返回-1。
*/

int longestSubsequenceLength(std::vector<int>& arr, int sum)
{
    if (arr.size() == 0 || sum <= 0)
    {
        return -1;
    }
    
    int start=0, end=0, nowNum = 0, maxLength = 0;

    while (end < arr.size())
    {
        nowNum += arr[end];
        if (nowNum == sum)
        {
            maxLength = std::max(maxLength, (end - start + 1));
        }
        else if (nowNum > sum)
        {
            nowNum -= arr[start];
            ++start;
        }
        ++end;
    }
    return maxLength > 0 ? maxLength : -1;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 2, 1, 1, 1, 1, 3, 4, 2, 2, 2};
    int sum = 6;
    int result = longestSubsequenceLength(arr, sum);
    std::cout << "longest subsequece length = " << result << std::endl;
    return 0; 
}