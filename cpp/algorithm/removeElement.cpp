#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int n = nums.size();
    int index = 0; // 慢指针，指向不等于val的元素
    for (int i = 0; i < n; ++i) {
        if (nums[i] != val) {
            nums[index] = nums[i];
            ++index;
        }
    }
    nums.erase(nums.begin()+index, nums.end());
    return index; // 返回新的数组长度
}

int main() {
    std::vector<int> nums = {3, 2, 2, 3, 4, 5, 3, 6};
    int val = 3;

    int newLength = removeElement(nums, val);

    std::cout << "New array length: " << newLength << " " << nums.size()<< std::endl;
    std::cout << "Updated array: ";
    
    for (int i = 0; i < newLength; ++i) {
        std::cout << nums[i] << " ";
    }

    return 0;
}
