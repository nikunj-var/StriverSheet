//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    int timer = 0;
    void dfs(int node, int parent, vector<int> &visited, int time[], int low[], vector<int> &mark, vector<int> adj[])
    {
        visited[node] = 1;
        time[node] = low[node] = timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }
            if (!visited[it])
            {
                dfs(it, node, visited, time, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= time[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], time[it]);
            }
        }
        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int v, vector<int> adj[])
    {
        vector<int> vis(v, 0);
        int time[v];
        int low[v];
        vector<int> mark(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, time, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < v; i++)
        {
            if (mark[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
        {
            return {-1};
        }
        return ans;
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
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends