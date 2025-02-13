#include <chrono>
#include <iostream>
#include <math.h>
using namespace std;

void magicSquare(int n)
{
    int row = 0;
    int column = n / 2;
    int a[n][n];
    for (int i = 1; i <= n * n; i++)
    {
        a[row][column] = i;
        if (i % n == 0)
            row++;
        else
        {
            row--;
            column--;
        }
        if (column < 0)
            column = n - 1;
        if (column >= n)
            column = 0;
        if (row < 0)
            row = n - 1;
        if (row >= n)
            row = 0;
    }
}

int main()
{
    cout << "size ,time\n";
    for (int n = 5; n < 1000; n += 2)
    {
        cout << n;
        long res = 0;
        for (int m = 0; m < 10; ++m)
        {

            auto start = std::chrono::high_resolution_clock::now();
            magicSquare(n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration =
                std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            res += duration.count();
        }
        cout << "," << res / 10 << "\n";
    }
    return 0;
}