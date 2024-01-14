#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int left, int right)
{
    int pivot = nums[left];
    int i = left+1;
    int j = right;
    while(i<=j)
    {
        if(nums[i]<pivot)
        {
            i++;
        }
        else if(nums[j]>=pivot)
        {
            j--;
        }
        else
        {
            swap(nums[i++], nums[j--]);
        }
    }
    swap(nums[left], nums[j]);
    return j;
}

void quick_sort(vector<int> &nums, int left, int right)
{
    if(left<right)
    {
        int pivot = partition(nums, left, right);
        quick_sort(nums, left, pivot-1);
        quick_sort(nums, pivot+1, right);
    }
}

int main()
{
    vector<int> test{23, 1, 2, 4, 7, 2, 6, 3, 5, 6, 2, 88, 0, 22, 34, 1, 5};
    quick_sort(test, 0, test.size()-1);
    for(auto i: test)
    {
        cout << i << " ";
    }
    return 0;
}