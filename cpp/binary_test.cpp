#include <iostream>

template<typename T>
T binarySearch(T arr[], T val, int lens)
{
    int left = 0;
    int right = lens-1;
    while(left<=right)
    {
        int mid = (left + right) / 2;
        if(mid==val)
        {
            return mid;
        }
        else if(mid>val)
        {
            right = mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return -1;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int target = 11;

    int result = binarySearch(nums, target, sizeof(nums)/sizeof(int));

    if (result != -1) {
        std::cout << "target: " << target << " find in " << result << std::endl;
    } else {
        std::cout << "no target: " << target << " find" << std::endl;
    }

    return 0;
}