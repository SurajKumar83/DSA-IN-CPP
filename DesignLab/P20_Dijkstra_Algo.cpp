#include <bits/stdc++.h>
using namespace std;

void minimum_dis(int src, vector<int> &dist, vector<int> &parent, vector<pair<int, int>> adj[])
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {

        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        for (auto it : adj[node])
        {
            int curwt = it.second;
            int curnode = it.first;
            if (dist[curnode] > dis + curwt)
            {
                dist[curnode] = dis + curwt;
                pq.push({dist[curnode], curnode});
                parent[curnode] = node;
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    vector<pair<int, int>> adj[n];
    cout << "Enter the edges " << endl;
    int u, v, wt;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> parent(n + 1, -1);
    vector<int> dist(n + 1, INT_MAX);

    minimum_dis(0, dist, parent, adj);

    for (int i = 0; i < n; i++)
    {
        cout << "Path from " << 0 << " to node " << i << " is:";
        int node = i;
        while (parent[node] > -1)
        {
            cout << parent[node] << "->";
            node = parent[node];
        }
        cout << " Distance " << dist[i] << endl;
    }
}