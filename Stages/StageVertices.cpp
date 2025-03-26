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

vector<vector<int>> getStageVertices(vector<vector<int>> &graph, int n)
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

    vector<vector<int>> vertices(max);
    for (int i = 0; i < n; i++)
    {
        if (stage[i] > 0)
        {
            vertices[stage[i] - 1].push_back(i);
        }
    }

    return vertices;
}

int main()
{
    int n = 8;
    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

    graph[0][1] = 1;
    graph[0][2] = 2;
    graph[0][3] = 5;
    graph[1][4] = 4;
    graph[1][5] = 11;
    graph[2][4] = 9;
    graph[2][5] = 5;
    graph[2][6] = 16;
    graph[3][6] = 2;
    graph[4][7] = 18;
    graph[5][7] = 13;
    graph[6][7] = 2;

    int count = countStages(graph, n);
    cout << "number of stages: " << count << endl;

    vector<vector<int>> vertices = getStageVertices(graph, n);
    cout << "vertices in each stage:" << endl;
    for (int i = 0; i < vertices.size(); i++)
    {
        cout << "stage " << i + 1 << ": ";
        for (int j = 0; j < vertices[i].size(); j++)
        {
            cout << vertices[i][j];
            if (j < vertices[i].size() - 1)
                cout << ", ";
        }
        cout << endl;
    }

    return 0;
}