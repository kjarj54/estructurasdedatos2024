//Kruskal

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

int find(vector<int>& parent, int i) {
    return parent[i] == i ? i : find(parent, parent[i]);
}

void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskalMST(Graph& graph) {
    vector<Edge> result;
    int e = 0, i = 0;

    sort(graph.edges.begin(), graph.edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(graph.V), rank(graph.V, 0);
    for (int v = 0; v < graph.V; v++)
        parent[v] = v;

    while (e < graph.V - 1 && i < graph.E) {
        Edge next_edge = graph.edges[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            e++;
            unionSet(parent, rank, x, y);
        }
    }

    cout << "Aristas del MST:\n";
    for (auto& edge : result)
        cout << edge.src << " - " << edge.dest << " \t" << edge.weight << endl;
}

int main() {
    Graph graph = {4, 5, {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}}};
    kruskalMST(graph);
    return 0;
}
