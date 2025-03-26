#include <iostream>
#include <vector>
using namespace std;

void add(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<int>> &c, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void sub(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<int>> &c, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void split(vector<vector<int>> &parent, vector<vector<int>> &child, int row, int col, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            child[i][j] = parent[i + row][j + col];
        }
    }
}

void join(vector<vector<int>> &parent, vector<vector<int>> &child, int row, int col, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            parent[i + row][j + col] = child[i][j];
        }
    }
}

void strassen(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<int>> &c, int size)
{
    if (size == 1)
    {
        c[0][0] = a[0][0] * b[0][0];
        return;
    }

    if (size <= 64)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < size; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return;
    }

    int half = size / 2;

    vector<vector<int>> a11(half, vector<int>(half));
    vector<vector<int>> a12(half, vector<int>(half));
    vector<vector<int>> a21(half, vector<int>(half));
    vector<vector<int>> a22(half, vector<int>(half));

    vector<vector<int>> b11(half, vector<int>(half));
    vector<vector<int>> b12(half, vector<int>(half));
    vector<vector<int>> b21(half, vector<int>(half));
    vector<vector<int>> b22(half, vector<int>(half));

    vector<vector<int>> c11(half, vector<int>(half));
    vector<vector<int>> c12(half, vector<int>(half));
    vector<vector<int>> c21(half, vector<int>(half));
    vector<vector<int>> c22(half, vector<int>(half));

    vector<vector<int>> t1(half, vector<int>(half));
    vector<vector<int>> t2(half, vector<int>(half));

    vector<vector<int>> p1(half, vector<int>(half));
    vector<vector<int>> p2(half, vector<int>(half));
    vector<vector<int>> p3(half, vector<int>(half));
    vector<vector<int>> p4(half, vector<int>(half));
    vector<vector<int>> p5(half, vector<int>(half));
    vector<vector<int>> p6(half, vector<int>(half));
    vector<vector<int>> p7(half, vector<int>(half));

    split(a, a11, 0, 0, half);
    split(a, a12, 0, half, half);
    split(a, a21, half, 0, half);
    split(a, a22, half, half, half);

    split(b, b11, 0, 0, half);
    split(b, b12, 0, half, half);
    split(b, b21, half, 0, half);
    split(b, b22, half, half, half);

    add(a11, a22, t1, half);
    add(b11, b22, t2, half);
    strassen(t1, t2, p1, half);

    add(a21, a22, t1, half);
    strassen(t1, b11, p2, half);

    sub(b12, b22, t1, half);
    strassen(a11, t1, p3, half);

    sub(b21, b11, t1, half);
    strassen(a22, t1, p4, half);

    add(a11, a12, t1, half);
    strassen(t1, b22, p5, half);

    sub(a21, a11, t1, half);
    add(b11, b12, t2, half);
    strassen(t1, t2, p6, half);

    sub(a12, a22, t1, half);
    add(b21, b22, t2, half);
    strassen(t1, t2, p7, half);

    add(p1, p4, t1, half);
    sub(t1, p5, t2, half);
    add(t2, p7, c11, half);

    add(p3, p5, c12, half);

    add(p2, p4, c21, half);

    sub(p1, p2, t1, half);
    add(t1, p3, t2, half);
    add(t2, p6, c22, half);

    join(c, c11, 0, 0, half);
    join(c, c12, 0, half, half);
    join(c, c21, half, 0, half);
    join(c, c22, half, half, half);
}

bool isPow2(int n)
{
    return (n != 0) && ((n & (n - 1)) == 0);
}

int nextPow2(int n)
{
    int pow = 1;
    while (pow < n)
    {
        pow *= 2;
    }
    return pow;
}

void print(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "enter size of square matrices: ";
    cin >> n;

    int size = n;
    if (!isPow2(n))
    {
        size = nextPow2(n);
    }

    vector<vector<int>> a(size, vector<int>(size, 0));
    vector<vector<int>> b(size, vector<int>(size, 0));
    vector<vector<int>> c(size, vector<int>(size, 0));

    cout << "enter elements of first matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "enter elements of second matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
        }
    }

    strassen(a, b, c, size);

    cout << "result matrix:" << endl;
    print(c, n);

    return 0;
}
