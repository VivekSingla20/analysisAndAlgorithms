#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent;

public:
    DisjointSet(int size) {
        parent.resize(size, -1);
    }

    int findRoot(int node) {
        if (parent[node] < 0) return node;
        return parent[node] = findRoot(parent[node]);
    }

    bool merge(int a, int b) {
        int rootA = findRoot(a);
        int rootB = findRoot(b);

        if (rootA == rootB) return false;

        if (parent[rootA] < parent[rootB]) {
            parent[rootA] += parent[rootB];
            parent[rootB] = rootA;
        } else {
            parent[rootB] += parent[rootA];
            parent[rootA] = rootB;
        }

        return true;
    }
};

bool compareEdges(const vector<int>& edge1, const vector<int>& edge2) {
    return edge1[0] > edge2[0];
}

void buildMST(int totalNodes, vector<vector<int>>& allEdges) {
    priority_queue<vector<int>, vector<vector<int>>, function<bool(vector<int>&, vector<int>&)>> edges(compareEdges, allEdges);

    DisjointSet dsu(totalNodes);
    int cost = 0, edgesAdded = 0;

    while (!edges.empty() && edgesAdded < totalNodes - 1) {
        auto edge = edges.top();
        edges.pop();

        int weight = edge[0];
        int from = edge[1];
        int to = edge[2];

        if (dsu.merge(from, to)) {
            cost += weight;
            edgesAdded++;
            cout << "Picked edge: " << from << " - " << to << " (Cost: " << weight << ")\n";
        }
    }

    if (edgesAdded == totalNodes - 1) {
        cout << "Total MST cost: " << cost << "\n";
    } else {
        cout << "MST not possible\n";
    }
}

int main() {
    int nodes = 5;

    vector<vector<int>> edges = {
        {2, 0, 1}, {3, 1, 2}, {7, 2, 4},
        {5, 1, 4}, {9, 3, 4}, {6, 0, 3},
        {8, 1, 3}
    };

    buildMST(nodes, edges);

    return 0;
}
