#include <iostream>
using namespace std;

void findMaxMin(int arr[], int low, int high, int& max, int& min) {
    if (low == high) {
        max = min = arr[low];
        return;
    }
    
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            max = arr[low];
            min = arr[high];
        } else {
            max = arr[high];
            min = arr[low];
        }
        return;
    }
    
    int mid = (low + high) / 2;
    int max1, min1, max2, min2;
    
    findMaxMin(arr, low, mid, max1, min1);
    findMaxMin(arr, mid + 1, high, max2, min2);
    
    max = (max1 > max2) ? max1 : max2;
    min = (min1 < min2) ? min1 : min2;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int max, min;
    findMaxMin(arr, 0, n-1, max, min);
    
    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;
    
    return 0;
} 