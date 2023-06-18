#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &s)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, s);
            }
        }
        s.push(node);
    }
    void dfs2(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs2(it, vis, adj);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<vector<int>> &adj)
    {
        // step1- do topological sort
        // step2- reverse graph
        // step3- do dfs
        vector<int> vis(v, 0);
        stack<int> s;
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, s);
            }
        }
        vector<int> adjtraverse[v];
        for (int i = 0; i < v; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                adjtraverse[it].push_back(i);
            }
        }
        int scc = 0;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (!vis[node])
            {
                scc++;
                dfs2(node, vis, adjtraverse);
            }
        }
        return scc;
    }
};