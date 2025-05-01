#include <iostream>
using namespace std;

void sumOfSubsets(int arr[], int n, int target, int currentSum, int index, int solution[]) {
    if (currentSum == target) {
        cout << "Solution found: ";
        for (int i = 0; i < n; i++) {
            if (solution[i] == 1) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        return;
    }
    
    if (index >= n || currentSum > target) {
        return;
    }
    
    // Include current element
    solution[index] = 1;
    sumOfSubsets(arr, n, target, currentSum + arr[index], index + 1, solution);
    
    // Exclude current element
    solution[index] = 0;
    sumOfSubsets(arr, n, target, currentSum, index + 1, solution);
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
    
    int target;
    cout << "Enter target sum: ";
    cin >> target;
    
    int solution[100] = {0};
    cout << "\nPossible solutions:\n";
    sumOfSubsets(arr, n, target, 0, 0, solution);
    
    return 0;
}