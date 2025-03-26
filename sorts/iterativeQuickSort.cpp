#include <iostream>
#include <stack>
using namespace std;

int divide(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    stack<pair<int, int>> s;

    s.push({low, high});

    while (!s.empty())
    {
        low = s.top().first;
        high = s.top().second;
        s.pop();

        if (low < high)
        {
            int mid = divide(arr, low, high);

            if (mid - 1 > low)
            {
                s.push({low, mid - 1});
            }

            if (mid + 1 < high)
            {
                s.push({mid + 1, high});
            }
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
