#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void topologicalSortDFSUtil(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSortDFS();
    void topologicalSortBFS();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::topologicalSortDFSUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i])
        {
            topologicalSortDFSUtil(*i, visited, Stack);
        }
    }
    Stack.push(v);
}

void Graph::topologicalSortDFS()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            topologicalSortDFSUtil(i, visited, Stack);
        }
    }
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    delete[] visited;
}

void Graph::topologicalSortBFS()
{
    vector<int> in_degree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto itr = adj[i].begin(); itr != adj[i].end(); itr++)
        {
            in_degree[*itr]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (in_degree[i] == 0)
            q.push(i);
    }

    int cnt = 0;

    vector<int> top_order;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        for (auto itr = adj[u].begin(); itr != adj[u].end(); itr++)
        {
            if (--in_degree[*itr] == 0)
                q.push(*itr);
        }

        cnt++;
    }

    if (cnt != V)
    {
        cout << "There exists a cycle in the graph\n";
        return;
    }

    for (int i = 0; i < top_order.size(); i++)
    {
        cout << top_order[i] << " ";
    }
    cout << endl;
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << "Topological Sort of the given graph is: ";
    g.topologicalSortDFS();
    return 0;
}