#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int nums[12] = {1, 2, 1, 10, 1, 3, 2, 3, 4, 2, 9, 10};
    std::vector<int> vecNums(nums, nums + 12);

    std::for_each(vecNums.begin(), vecNums.end(), [](int itor){std::cout << itor << " ";});
    std::cout << std::endl;

    vecNums.erase(vecNums.begin() + 1); // 逐个删除
    vecNums.erase(vecNums.begin() + 8);
    std::for_each(vecNums.begin(), vecNums.end(), [](int itor){std::cout << itor << " ";});
    std::cout << std::endl;

    vecNums.erase(vecNums.begin() + 8, vecNums.end()); // 批量删除
    std::for_each(vecNums.begin(), vecNums.end(), [](int itor){std::cout << itor << " ";});
    std::cout << std::endl;

    vecNums.pop_back(); // 弹出最后一个
    std::for_each(vecNums.begin(), vecNums.end(), [](int itor){std::cout << itor << " ";});
    std::cout << std::endl;

    int delNum = 1;
    std::vector<int>::iterator itor = vecNums.begin();
    while (itor != vecNums.end())
    {
        if (*itor == 1)
        {
            vecNums.erase(itor);
        }
        else
        {
            ++itor;
        }
    }
    std::for_each(vecNums.begin(), vecNums.end(), [](int itor){std::cout << itor << " ";});
    std::cout << std::endl;

    std::vector<int>::iterator removeItor;
    removeItor = remove(vecNums.begin(), vecNums.end(), 10); // 删除
    std::for_each(vecNums.begin(), vecNums.end(), [](int itor){std::cout << itor << " ";}); // 将要删除的元素移动到vector末尾
    std::cout << std::endl;
    vecNums.erase(removeItor, vecNums.end());  // 删除元素
    std::for_each(vecNums.begin(), vecNums.end(), [](int itor){std::cout << itor << " ";});
    std::cout << std::endl;

    return 0;
}