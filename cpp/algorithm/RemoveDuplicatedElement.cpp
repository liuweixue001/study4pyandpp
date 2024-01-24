#include <iostream>
#include <vector>
#include <algorithm>

/*
给你一个 非严格递增排列 的数组 nums ，请你原地删除重复出现的元素，
使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
然后返回 nums 中唯一元素的个数。
*/

int removeDuplicatedElementV1(std::vector<int>& nums)
{
    if (nums.empty())
    {
        return 0;
    }

    int slow = 0;
    for (int fast = 1; fast < nums.size(); ++fast)
    {
        if (nums[slow] != nums[fast])
        {
            nums[++slow] = nums[fast];
        }
    }
    return slow+1;
}

/*
给你一个有序数组 nums ，请你原地删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

int removeDuplicatedElementV2(std::vector<int>& nums)
{
    if (nums.size() < 3)
    {
        return nums.size();
    }

    int slow = 2;
    for (int fast = 2; fast < nums.size(); ++fast)
    {
        if (nums[slow-2] != nums[fast]) // 前快指针元素是否与当前慢指针的前两个元素相等
        {
            nums[slow++] = nums[fast]; // 如果不相等则更新满指针元素，并+1, 这里+1后的元素可能与当前元素相等，但仅两个元素相等不影响结果
        }
        // 如果相等则仅++快指针
    }
    return slow;
}


int main()
{
    std::vector<int> test{0, 0, 0, 0, 1, 2, 3, 4, 66, 77, 77, 77, 88, 88, 88, 88};
    // int result = removeDuplicatedElementV1(test);
    int result = removeDuplicatedElementV2(test);
    std::cout << "after remove duplicated elements, nums.size() is " << result << std::endl;
    std::for_each(test.begin(), test.begin() + result, [](int value){std::cout << value << " ";});
}