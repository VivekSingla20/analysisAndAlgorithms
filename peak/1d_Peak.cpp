#include <iostream>
using namespace std;

int findPeak(int arr[], int low, int high, int n)
{
    int mid = (low + high) / 2;

    if ((mid == 0 || arr[mid] >= arr[mid - 1]) &&
        (mid == n - 1 || arr[mid] >= arr[mid + 1]))
    {
        return mid;
    }

    if (mid > 0 && arr[mid] < arr[mid - 1])
        return findPeak(arr, low, mid - 1, n);
    return findPeak(arr, mid + 1, high, n);
}

int main()
{
    int arr[] = {8, 7, 6, 5, 3, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int peakIndex = findPeak(arr, 0, n - 1, n);
    cout << "Peak is at index " << peakIndex << " with value " << arr[peakIndex] << endl;

    return 0;
}
