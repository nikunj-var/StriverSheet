//{ Driver Code Starts
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int> dist(v, INT_MAX);
        set<pair<int, int>> st;
        dist[s] = 0;
        st.insert(make_pair(0, s));
        while (!st.empty())
        {
            auto top = *(st.begin());
            int nodedistance = top.first;
            int topnode = top.second;
            st.erase(st.begin());
            for (auto node : adj[topnode])
            {
                if (nodedistance + node[1] < dist[node[0]])
                {
                    auto record = st.find(make_pair(dist[node[0]], node[0]));
                    if (record != st.end())
                    {
                        st.erase(record);
                    }
                    dist[node[0]] = nodedistance + node[1];
                    st.insert(make_pair(dist[node[0]], node[0]));
                }
            }
        }
        return dist;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends