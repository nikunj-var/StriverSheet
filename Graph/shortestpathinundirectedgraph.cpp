//{ Driver Code Starts
// Initial Template for C++

#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int n, int m, int src)
    {
        vector<int> adj[n];
        for (int i = 0; i < m; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, -1);
        unordered_map<int, int> parent;

        queue<int> q;
        q.push(src);
        visited[src] = 0;
        int dist = 0;
        while (!q.empty())
        {
            dist++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int front = q.front();
                q.pop();

                for (auto node : adj[front])
                {
                    if (visited[node] == -1)
                    {
                        visited[node] = dist;
                        q.push(node);
                    }
                }
            }
        }
        return visited;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 2; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends