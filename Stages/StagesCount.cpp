#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int countStages(vector<vector<int>> &graph, int n)
{
    vector<int> stage(n, 0);
    stage[0] = 1;

    for (int i = 0; i < n; i++)
    {
        if (stage[i] == 0)
            continue;

        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != 0 && graph[i][j] != INT_MAX)
            {
                if (stage[j] == 0 || stage[j] < stage[i] + 1)
                {
                    stage[j] = stage[i] + 1;
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (stage[i] > max)
        {
            max = stage[i];
        }
    }

    return max;
}

int main()
{
    int n;
    cout << "enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

    cout << "enter adjacency matrix (-1 for no edge):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int w;
            cin >> w;
            if (w == -1)
            {
                graph[i][j] = INT_MAX;
            }
            else
            {
                graph[i][j] = w;
            }
        }
    }

    int count = countStages(graph, n);
    cout << "number of stages: " << count << endl;

    return 0;
}