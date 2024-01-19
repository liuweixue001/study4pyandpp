#include <iostream>
#include <vector>
#include <algorithm>

/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，
nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

没有注意到n和m, 没有使用
*/


void orderedNumbers(std::vector<int>& arr1, std::vector<int>& arr2)
{
    int arrSize1 = arr1.size(), arrSize2 = arr2.size();
    if (arrSize1 == 0 && arrSize2!=0)
    {
        arr1 = arr2;
        return;
    }
    
    std::vector<int> tmp(arrSize1 - arrSize2);
    std::copy(arr1.begin(), arr1.begin() + arrSize1, tmp.begin());

    int tmpIndex = 0, arr2Index = 0;
    for (int i = 0; i < arrSize1; ++i)
    {
        if (tmpIndex < tmp.size() && arr2Index < arrSize2)
        {
            if (tmp[tmpIndex] <= arr2[arr2Index])
            {
                arr1[i] = tmp[tmpIndex];
                tmpIndex++;
            }
            else
            {
                arr1[i] = arr2[arr2Index];
                arr2Index++;
            }
        }
        else if (tmpIndex < tmp.size())
        {
            arr1[i] = tmp[tmpIndex];
            tmpIndex++;
        }
        else if (arr2Index < arrSize2)
        {
            arr1[i] = arr2[arr2Index];
            arr2Index++;
        }
    }
}

void orderedNumbers(std::vector<int>& arr1, const int& n, std::vector<int>& arr2, const int& m)
{
    int p = n + m -1, p1 = n - 1, p2 = m - 1;
    while (p1 >= 0 && p2 >= 0)
    {
        if (arr1[p1] >= arr2[p2])
        {
            arr1[p--] = arr1[p1--];
        }
        else 
        {
            arr1[p--] = arr2[p2--];
        }
    }
    while (p2 >= 0)
    {
        arr1[p--] = arr2[p2--];
    }
}

int main()
{
    // std::vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    // std::vector<int> arr2 = {2, 5, 6};
    // std::vector<int> arr1 = {1};
    // std::vector<int> arr2 = {};
    std::vector<int> arr1 = {0};
    std::vector<int> arr2 = {1};
    // orderedNumbers(arr1, arr2);
    orderedNumbers(arr1, 0, arr2, 1);
    std::for_each(arr1.begin(), arr1.end(), [](int value){std::cout << value << " ";});
    return 0;
}