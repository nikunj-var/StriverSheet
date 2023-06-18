//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// using bfs
// } Driver Code Ends
class Solution
{
public:
    bool bipartite(int node, vector<int> adj[], vector<int> &color)
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            for (auto i : adj[temp])
            {
                if (color[i] == -1)
                {
                    color[i] = 1 - color[temp];
                    q.push(i);
                }
                else if (color[i] == color[temp])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(int v, vector<int> adj[])
    {
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (!bipartite(i, adj, color))
                {
                    return false;
                }
            }
        }
        return true;
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
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

// using dfs
//{ Driver Code Starts

// } Driver Code Ends
class Solution
{
public:
    bool bipartite(int node, vector<int> adj[], vector<int> &color)
    {
        if (color[node] == -1)
        {
            color[node] = 1;
        }
        for (auto i : adj[node])
        {
            if (color[i] == -1)
            {
                color[i] = 1 - color[node];
                if (!bipartite(i, adj, color))
                {
                    return false;
                }
            }
            else if (color[i] == color[node])
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(int v, vector<int> adj[])
    {
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (!bipartite(i, adj, color))
                {
                    return false;
                }
            }
        }
        return true;
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
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends