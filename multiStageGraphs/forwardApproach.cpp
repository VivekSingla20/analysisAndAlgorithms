#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int forwardApproach(vector<vector<int>> &graph, int n, int stages)
{
    vector<int> cost(n, INT_MAX);
    vector<int> path(stages);
    vector<int> prev(n);

    cost[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] != INT_MAX && cost[i] != INT_MAX)
            {
                if (cost[j] > cost[i] + graph[i][j])
                {
                    cost[j] = cost[i] + graph[i][j];
                    prev[j] = i;
                }
            }
        }
    }

    int curr = n - 1;
    int idx = stages - 1;
    path[idx] = n - 1;

    while (curr != 0)
    {
        curr = prev[curr];
        idx--;
        path[idx] = curr;
    }

    cout << "shortest path cost: " << cost[n - 1] << endl;
    cout << "path: ";
    for (int i = 0; i < stages; i++)
    {
        cout << path[i];
        if (i < stages - 1)
            cout << " -> ";
    }
    cout << endl;

    return cost[n - 1];
}

int main()
{
    int n = 8;
    int stages = 4;

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

    graph[0][1] = 2;
    graph[0][2] = 1;
    graph[0][3] = 3;
    graph[1][4] = 2;
    graph[1][5] = 3;
    graph[2][4] = 6;
    graph[2][5] = 7;
    graph[3][5] = 6;
    graph[4][6] = 1;
    graph[4][7] = 4;
    graph[5][6] = 2;
    graph[5][7] = 5;

    int minCost = forwardApproach(graph, n, stages);

    return 0;
}