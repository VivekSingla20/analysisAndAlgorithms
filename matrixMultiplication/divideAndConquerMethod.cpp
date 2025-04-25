#include <iostream>
#include <vector>
using namespace std;

using Matrix = vector<vector<int>>;

Matrix create(int size) {
    return Matrix(size, vector<int>(size));
}

void add(const Matrix &a, const Matrix &b, Matrix &result, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void subtract(const Matrix &a, const Matrix &b, Matrix &result, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = a[i][j] - b[i][j];
}

void split(const Matrix &source, Matrix &part, int rowOffset, int colOffset, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            part[i][j] = source[i + rowOffset][j + colOffset];
}

void join(Matrix &target, const Matrix &part, int rowOffset, int colOffset, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            target[i + rowOffset][j + colOffset] = part[i][j];
}

void multiply(const Matrix &a, const Matrix &b, Matrix &result, int size) {
    if (size == 1) {
        result[0][0] = a[0][0] * b[0][0];
        return;
    }

    int half = size / 2;

    Matrix a11 = create(half), a12 = create(half), a21 = create(half), a22 = create(half);
    Matrix b11 = create(half), b12 = create(half), b21 = create(half), b22 = create(half);
    Matrix c11 = create(half), c12 = create(half), c21 = create(half), c22 = create(half);
    Matrix temp1 = create(half), temp2 = create(half);

    split(a, a11, 0, 0, half);
    split(a, a12, 0, half, half);
    split(a, a21, half, 0, half);
    split(a, a22, half, half, half);

    split(b, b11, 0, 0, half);
    split(b, b12, 0, half, half);
    split(b, b21, half, 0, half);
    split(b, b22, half, half, half);

    multiply(a11, b11, temp1, half);
    multiply(a12, b21, temp2, half);
    add(temp1, temp2, c11, half);

    multiply(a11, b12, temp1, half);
    multiply(a12, b22, temp2, half);
    add(temp1, temp2, c12, half);

    multiply(a21, b11, temp1, half);
    multiply(a22, b21, temp2, half);
    add(temp1, temp2, c21, half);

    multiply(a21, b12, temp1, half);
    multiply(a22, b22, temp2, half);
    add(temp1, temp2, c22, half);

    join(result, c11, 0, 0, half);
    join(result, c12, 0, half, half);
    join(result, c21, half, 0, half);
    join(result, c22, half, half, half);
}

bool isPowerOfTwo(int n) {
    return (n != 0) && ((n & (n - 1)) == 0);
}

int nextPowerOfTwo(int n) {
    int result = 1;
    while (result < n) result *= 2;
    return result;
}

void print(const Matrix &mat, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    int actualSize = isPowerOfTwo(n) ? n : nextPowerOfTwo(n);

    Matrix a = create(actualSize), b = create(actualSize), result = create(actualSize);

    cout << "Enter first matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter second matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];

    multiply(a, b, result, actualSize);

    cout << "Result:\n";
    print(result, n);

    return 0;
}
