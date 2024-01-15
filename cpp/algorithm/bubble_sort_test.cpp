#include <iostream>
#include <algorithm>

using namespace std;
template <typename T>
void bubbleSort(T arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    
    bubbleSort(arr, n);
    
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
