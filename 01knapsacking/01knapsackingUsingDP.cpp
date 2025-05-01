#include <iostream>
using namespace std;

int knapsack(int wt[], int val[], int n, int W) {
    int dp[100][100] = {0};  // Assuming max size of 100

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i-1] <= w) {
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // Print selected items
    cout << "Selected items: ";
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            cout << i << " ";
            w -= wt[i-1];
        }
    }
    cout << endl;

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    
    int wt[100], val[100];
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    
    cout << "Enter knapsack capacity: ";
    cin >> W;
    
    int maxValue = knapsack(wt, val, n, W);
    cout << "Maximum value: " << maxValue << endl;
    
    return 0;
}