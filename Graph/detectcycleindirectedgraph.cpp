// using bfs

//{ Driver Code Starts
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool solve(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, vector<int> adj[])
    {
        visited[node] = true;
        dfsvisited[node] = true;
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                bool cycledetected = solve(neighbour, visited, dfsvisited, adj);
                if (cycledetected)
                {
                    return true;
                }
            }
            else if (dfsvisited[neighbour])
            {
                return true;
            }
        }
        dfsvisited[node] = false;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[])
    {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                bool cycle = solve(i, visited, dfsvisited, adj);
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

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
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
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[])
    {
        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++)
        {
            vector<int> data = adj[i];
            for (auto j : data)
            {
                indegree[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto i : adj[front])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return (ans.size() == v) ? false : true;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends