#include <iostream>

template<typename T>
T binarySearch(T *arr, T val, int lens)
{
    int left = 0;
    int right = lens - 1;
    while (left <= right)
    {
        int med = (left + right) / 2;
        std::cout << left << " " << right << std::endl;
        if (arr[med] == val)
        {
            std::cout << 1 << std::endl;
            return med;
        }
        else if (val < arr[med])
        {
            std::cout << 2 << std::endl;
            right = med-1;
        }
        else
        {
            std::cout << 3 << std::endl;
            left = med+1;
        }
    }
    return -1;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int target = 5;

    int result = binarySearch(nums, target, sizeof(nums)/sizeof(int));

    if (result != -1) {
        std::cout << "target: " << target << " find in " << result << std::endl;
    } else {
        std::cout << "no target: " << target << " find" << std::endl;
    }

    return 0;
}