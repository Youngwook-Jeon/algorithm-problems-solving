#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void bridgeUtil(int u, vector<bool> &visited, vector<int> &disc,
                    vector<int> &low, int parent);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void bridge();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v); // Note: the graph is undirected
}

// A recursive function that finds and prints bridges using
// DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree

// low[] --> to keep track of the lowest possible time by which we can reach that vertex ‘other than parent’
// so that if edge from parent is removed can the particular node can be reached other than parent.
void Graph::bridgeUtil(int u, vector<bool> &visited, vector<int> &disc,
                       vector<int> &low, int parent)
{
    static int time = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;

        if (v == parent)
            continue;

        if (visited[v])
        {
            low[u] = min(low[u], disc[v]);
        }

        else
        {
            parent = u;
            bridgeUtil(v, visited, disc, low, parent);

            low[u] = min(low[u], low[v]);

            // if the lowest possible time to reach vertex v
            // is greater than discovery time of u it means
            // that v can be only be reached by vertex above v
            // so if that edge is removed v can't be reached so it's a bridge
            if (low[v] > disc[u])
                cout << u << " " << v << endl;
        }
    }
}

void Graph::bridge()
{
    vector<bool> visited(V, false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);

    int parent = -1;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}

int main()
{
    cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.bridge();

    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.bridge();

    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.bridge();

    return 0;
}