// using bfs

//{ Driver Code Starts
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool solve(vector<int> adj[], int node, unordered_map<int, bool> &visited)
    {
        unordered_map<int, int> parent;
        parent[node] = -1;
        queue<int> q;
        visited[node] = true;
        q.push(node);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto i : adj[front])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    parent[i] = front;
                }
                else if (visited[i] == true && i != parent[front])
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[])
    {
        unordered_map<int, bool> visited;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                bool cycle = solve(adj, i, visited);
                if (cycle)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

// using dfs
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool solve(vector<int> adj[], int node, int parent, unordered_map<int, bool> &visited)
    {
        visited[node] = true;
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                bool cycle = solve(adj, i, node, visited);
                if (cycle)
                {
                    return true;
                }
            }
            else if (parent != i)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[])
    {
        unordered_map<int, bool> visited;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                bool cycle = solve(adj, i, -1, visited);
                if (cycle)
                {
                    return true;
                }
            }
        }
        return false;
    }
};