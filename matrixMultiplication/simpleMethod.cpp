#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b)
{
    int n = a.size();
    int m = a[0].size();
    int p = b[0].size();

    vector<vector<int>> res(n, vector<int>(p, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < m; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}

void print(vector<vector<int>> &matrix)
{
    for (auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m, p;

    cout << "enter dimensions of first matrix (n m): ";
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    cout << "enter elements of first matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "enter dimensions of second matrix (m p): ";
    cin >> p;

    vector<vector<int>> b(m, vector<int>(p));
    cout << "enter elements of second matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> b[i][j];
        }
    }

    vector<vector<int>> res = multiply(a, b);

    cout << "result matrix:" << endl;
    print(res);

    return 0;
}
