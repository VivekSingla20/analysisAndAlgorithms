#include <iostream>
using namespace std;

int findMax(int arr[][4], int rows, int col)
{
    int maxIndex = 0;
    for (int i = 1; i < rows; i++)
    {
        if (arr[i][col] > arr[maxIndex][col])
            maxIndex = i;
    }
    return maxIndex;
}

pair<int, int> findPeak(int arr[][4], int rows, int cols, int leftCol, int rightCol)
{
    int midCol = (leftCol + rightCol) / 2;

    int maxRow = findMax(arr, rows, midCol);

    int maxElement = arr[maxRow][midCol];

    int leftNeighbor = (midCol > 0) ? arr[maxRow][midCol - 1] : -1;
    int rightNeighbor = (midCol < cols - 1) ? arr[maxRow][midCol + 1] : -1;

    if ((midCol == 0 || maxElement >= leftNeighbor) && (midCol == cols - 1 || maxElement >= rightNeighbor))
    {
        return {maxRow, midCol};
    }
    if (midCol > 0 && leftNeighbor > maxElement)
        return findPeak(arr, rows, cols, leftCol, midCol - 1);

    return findPeak(arr, rows, cols, midCol + 1, rightCol);
}

int main()
{
    int arr[4][4] = {
        {10, 20, 15, 5},
        {21, 30, 14, 13},
        {7, 16, 32, 9},
        {6, 17, 19, 11}};

    pair<int, int> peak = findPeak(arr, 4, 4, 0, 3);

    cout << "Peak found at (" << peak.first << ", " << peak.second << ") with value " << arr[peak.first][peak.second] << "\n";

    return 0;
}
