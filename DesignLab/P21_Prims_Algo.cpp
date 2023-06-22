#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cout << "Enter the number of node ";
    cin >> n;
    cout << "Enter the number of edges ";
    cin >> e;

    int u, v, wt;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<int> parent(n + 1, -1);
    vector<int> dist(n + 1, INT_MAX);
    vector<int> MSTvis(n + 1, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;

    pq.push({0, 1});
    int minimumcost = 0;
    for (int count = 1; count <= n - 1; count++)
    {
        int node = pq.top().second; // minimum weight element
        pq.pop();

        MSTvis[node] = true;

        for (auto it : adj[node])
        {
            int nextnode = it.first;
            int weight = it.second;
            if (MSTvis[nextnode] == false && weight < dist[nextnode])
            {
                parent[nextnode] = node;
                dist[nextnode] = weight;
                pq.push({dist[nextnode], nextnode});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        minimumcost += dist[i];
    }
    cout << "The minimum cost for MST: " << minimumcost << endl;
    return 0;
}