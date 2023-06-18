#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &visited, vector<int> adj[], int time[], int low[], vector<vector<int>> &bridges)
    {
        visited[node] = 1;
        time[node] = low[node] = timer++;
        for (auto neighbour : adj[node])
        {
            if (neighbour == parent)
            {
                continue;
            }
            if (visited[neighbour] == 0)
            {
                dfs(neighbour, node, visited, adj, time, low, bridges);
                low[node] = min(low[node], low[neighbour]);
                if (low[neighbour] > time[node])
                {
                    bridges.push_back({neighbour, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[neighbour]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        int time[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, visited, adj, time, low, bridges);
        return bridges;
    }
};