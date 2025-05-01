#include <iostream>
using namespace std;

int n;
int x[100];

bool place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}

void printBoard() {
    cout << "\nSolution:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void NQueen(int k) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                printBoard();
            } else {
                NQueen(k + 1);
            }
        }
    }
}

int main() {
    cout << "Enter number of queens (recommended: 4-8): ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid input. Please enter a positive number.\n";
        return 1;
    }
    
    cout << "\nFinding solutions for " << n << " queens...\n";
    NQueen(1);
    
    return 0;
}