#include <iostream>
using namespace std;

void printParenthesis(int s[][100], int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printParenthesis(s, i, s[i][j]);
        printParenthesis(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void matrixChainMultiplication(int p[], int n) {
    int m[100][100] = {0};  // cost matrix
    int s[100][100] = {0};  // split matrix
    
    // Fill the cost matrix
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = 999999;  // Initialize with a large value
            
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] + p[i] * p[k+1] * p[j+1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    
    cout << "Minimum number of multiplications: " << m[0][n-1] << endl;
    cout << "Optimal Parenthesization: ";
    printParenthesis(s, 0, n-1);
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    
    int p[100];
    cout << "Enter dimensions array (size " << n+1 << "): ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }
    
    matrixChainMultiplication(p, n);
    return 0;
}
