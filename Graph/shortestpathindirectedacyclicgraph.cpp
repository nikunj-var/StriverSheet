#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;
class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addedge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }
} g;
void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s)
{
    visited[node] = true;
    for (auto neighbour : g.adj[node])
    {
        if (!visited[neighbour.first])
        {
            dfs(neighbour.first, visited, s);
        }
    }
    s.push(node);
}
void getshortestpath(int src, vector<int> &dist, vector<int> &toposort)
{
    dist[src] = 0;
    for (int i = 0; i < toposort.size(); i++)
    {
        int top = toposort[i];
        if (dist[top] != INT_MAX)
        {
            for (auto i : g.adj[top])
            {
                if (dist[top] + i.second < dist[i.first])
                {
                    dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }
}
int main()
{
    int n = 6;
    graph g;
    g.addedge(0, 1, 5);
    g.addedge(0, 2, 3);
    g.addedge(1, 2, 2);
    g.addedge(1, 3, 6);
    g.addedge(2, 3, 7);
    g.addedge(2, 4, 4);
    g.addedge(2, 5, 2);
    g.addedge(3, 4, -1);
    g.addedge(4, 5, -2);
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, s);
        }
    }
    int src = 0;
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    vector<int> toposort;
    while (!s.empty())
    {
        toposort.push_back(s.top());
        s.pop();
    }
    getshortestpath(src, dist, toposort);

    reverse(toposort.begin(), toposort.end());
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
}