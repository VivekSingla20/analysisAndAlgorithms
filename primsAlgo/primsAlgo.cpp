#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findSmallest(vector<int> &key, vector<bool> &visited, int n)
{
    int min = INT_MAX, idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            idx = i;
        }
    }
    return idx;
}

void display(vector<int> &path, vector<vector<int>> &graph, int n)
{
    cout << "edge \tweight\n";
    for (int i = 1; i < n; i++)
    {
        cout << path[i] << " - " << i << "\t" << graph[i][path[i]] << "\n";
    }
}

void prim(vector<vector<int>> &graph, int n)
{
    vector<int> path(n);
    vector<int> key(n, INT_MAX);
    vector<bool> visited(n, false);

    key[0] = 0;
    path[0] = -1;

    for (int i = 0; i < n - 1; i++)
    {
        int u = findSmallest(key, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                path[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    display(path, graph, n);
}

int main()
{
    int n = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    prim(graph, n);

    return 0;
}